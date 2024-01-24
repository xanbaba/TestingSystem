#include "test_logic.h"

#include <fstream>

#include "stopped_test_logic.h"
#include "../single_include/nlohmann/json.hpp"

using json = nlohmann::json;

test_logic::~test_logic()
{
    delete test_object;
}

test_logic::test_logic(test& a_test_object)
{
    correct_answers = 0;
    question_amount = static_cast<int>(a_test_object.get_questions_list().size());
    test_object = new test{a_test_object};
    is_stopped = false;
}

test_logic::test_logic(const stopped_test& a_stopped_test_object)
{
    correct_answers = static_cast<int>(a_stopped_test_object.get_correct_answers());
    test_object = new test{stopped_test_logic::get_test_by_id(a_stopped_test_object.get_id())};
    question_amount = static_cast<int>(test_object->get_questions_list().size());
    is_stopped = true;
}

void test_logic::run_checker(size_t question_index, size_t answer_index)
{
    const auto answers_list = test_object->get_questions_list()[question_index].get_question_answers_list();
    if (answers_list[answer_index - 1].
        get_is_correct())
    {
        ++correct_answers;
    }
}

bool test_logic::is_answer_valid(size_t question_index, int answer_index) const
{
    const auto answers_list = test_object->get_questions_list()[question_index].get_question_answers_list();
    if (answer_index <= 0 || answer_index > static_cast<int>(answers_list.size() + 1))
    {
        return false;
    }
    return true;
}

size_t test_logic::get_grade() const
{
    return 12 * correct_answers / question_amount;
}

void test_logic::save_to_user(user& base_user) const
{
    json users_json;
    std::ifstream users_file{"data_base/users.json"};
    if (users_file.is_open())
    {
        users_json = json::parse(users_file);
        auto base_user_login = base_user.get_login();
        for (auto& user_object : users_json)
        {
            if (user_object["login"] == base_user_login)
            {
                user_object["passed_tests"].push_back({
                    {"score", get_grade()},
                    {"test_name", test_object->get_name()}
                });
                base_user.get_passed_tests().emplace_back(
                    test_object->get_name(),
                    get_grade()
                );
                if (is_stopped)
                {
                    json new_stopped_test_json = json::array();
                    for (size_t i = 0; i < user_object["stopped_tests"].size(); ++i)
                    {
                        if (user_object["stopped_tests"][i]["id"] == test_object->get_id())
                        {
                            base_user.get_stopped_tests().erase(
                                base_user.get_stopped_tests().begin() + static_cast<long long>(i));
                            continue;
                        }
                        new_stopped_test_json.push_back(user_object["stopped_tests"][i]);
                    }
                    user_object["stopped_tests"] = new_stopped_test_json;
                }
                break;
            }
        }
        users_file.close();
    }

    std::ofstream users_write("data_base/users.json");
    if (users_write.is_open())
    {
        users_write << std::setw(2) << users_json;
        users_write.close();
    }
}

bool test_logic::is_stopping_test(size_t answer_index, size_t question_index) const
{
    if (answer_index == test_object->get_questions_list()[question_index].get_question_answers_list().size() + 1)
    {
        return true;
    }
    return false;
}

void test_logic::stop_test(user& base_user, size_t question_index) const
{
    json users_json;
    std::ifstream users_file{"data_base/users.json"};
    if (users_file.is_open())
    {
        users_json = json::parse(users_file);
        auto base_user_login = base_user.get_login();
        for (auto& user_object : users_json)
        {
            if (user_object["login"] == base_user_login)
            {
                bool is_unique = true;
                for (size_t i = 0; i < user_object["stopped_tests"].size(); ++i)
                {
                    auto& stopped_test_json = user_object["stopped_tests"][i];
                    if (stopped_test_json["id"] == test_object->get_id())
                    {
                        stopped_test_json = {
                            {"id", test_object->get_id()},
                            {"question_number", question_index},
                            {"correct_answers", correct_answers}
                        };
                        base_user.get_stopped_tests()[i] = stopped_test{
                            static_cast<size_t>(test_object->get_id()), question_index,
                            static_cast<size_t>(correct_answers)
                        };
                        
                        is_unique = false;
                        break;
                    }
                }
                if (is_unique)
                {
                    user_object["stopped_tests"].push_back({
                        {"id", test_object->get_id()},
                        {"question_number", question_index},
                        {"correct_answers", correct_answers}
                    });
                    base_user.get_stopped_tests().emplace_back(test_object->get_id(), question_index, correct_answers);
                }
                break;
            }
        }
        users_file.close();
    }

    std::ofstream users_write("data_base/users.json");
    if (users_write.is_open())
    {
        users_write << std::setw(2) << users_json;
        users_write.close();
    }
}
