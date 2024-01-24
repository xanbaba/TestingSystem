#include "category_logic.h"

#include <fstream>

#include "../single_include/nlohmann/json.hpp"

using json = nlohmann::json;

std::vector<category> category_logic::get_categories()
{
    std::ifstream tests_file{"data_base/tests.json"};

    std::vector<category> categories_list;
    
    if (tests_file.is_open())
    {
        auto categories_list_json = json::parse(tests_file)["categories_list"];

        for (auto& category_json : categories_list_json)
        {
            auto tests_list_json = category_json["tests_list"];
            std::vector<test> tests_list;
            for (auto& test_json : tests_list_json)
            {
                auto question_list_json = test_json["questions_list"];
                std::vector<question> questions_list;
                for (auto& question_json : question_list_json)
                {
                    std::vector<question_answer> question_answers_list;
                    auto question_answers_list_json = question_json["question_answers_list"];
                    for (auto& answer_json : question_answers_list_json)
                    {
                        question_answers_list.emplace_back(answer_json["answer_text"], answer_json["is_correct"]);
                    }
                    questions_list.emplace_back(question_json["question_text"], question_answers_list);
                }
                tests_list.emplace_back(test_json["name"], questions_list, test_json["id"]);
            }
            categories_list.emplace_back(category_json["category_name"], tests_list);
        }
        tests_file.close();
    }

    return categories_list;
}
