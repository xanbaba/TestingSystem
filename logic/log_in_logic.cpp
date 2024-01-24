#include "log_in_logic.h"

#include <fstream>

#include "../logic/sha1.hpp"

#include "../single_include/nlohmann/json.hpp"

using json = nlohmann::json;

user* log_in_logic::get_user_by_login_password(const std::string& login, const std::string& password)
{
    SHA1 checksum;

    std::ifstream users_file{"data_base/users.json"};

    if (users_file.is_open())
    {
        json users_json = json::parse(users_file);
        for (auto user_object : users_json)
        {
            checksum.update(password);
            auto final = checksum.final();
            if (!(login != user_object["login"]) &&
                !(final != user_object["password"]))
            {
                std::vector<passed_test> passed_tests;
                for (auto& passed_test_json : user_object["passed_tests"])
                {
                    passed_tests.emplace_back(
                        passed_test_json["test_name"],
                        passed_test_json["score"]
                    );
                }

                std::vector<stopped_test> stopped_tests;
                for (auto& stopped_test_json : user_object["stopped_tests"])
                {
                    stopped_tests.emplace_back(
                        stopped_test_json["id"],
                        stopped_test_json["question_number"],
                        stopped_test_json["correct_answers"]
                    );
                }
                auto app_user = new user{
                    user_object["login"],
                    user_object["password"],
                    user_object["fio"],
                    user_object["phone_number"],
                    user_object["is_admin"],
                    passed_tests,
                    stopped_tests
                };
                return app_user;
            }
        }
        users_file.close();
    }

    return nullptr;
}
