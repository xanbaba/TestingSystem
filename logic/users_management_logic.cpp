#include "users_management_logic.h"

#include <fstream>

#include "sha1.hpp"
#include "../single_include/nlohmann/json.hpp"

std::vector<std::string> users_management_logic::get_users_logins()
{
    std::vector<std::string> users_logins;
    std::ifstream users_file{"data_base/users.json"};
    if (users_file.is_open())
    {
        auto users_json = nlohmann::json::parse(users_file);
        for (auto& user_json : users_json)
        {
            if (!user_json["is_admin"])
            {
                users_logins.push_back(user_json["login"]);
            }
        }
        users_file.close();
    }
    return users_logins;
}

void users_management_logic::change_user(const std::string& user_login, const std::string& new_login, const std::string& new_password)
{
    std::ifstream users_file{"data_base/users.json"};
    nlohmann::json users_json;
    if (users_file.is_open())
    {
        users_json = nlohmann::json::parse(users_file);
        for (auto& user_json : users_json)
        {
            if (user_json["login"] == user_login)
            {
                SHA1 checksum;
                checksum.update(new_password);
                user_json["login"] = new_login;
                user_json["password"] = checksum.final();
                break;
            }
        }
        users_file.close();
    }
    std::ofstream users_file_write{"data_base/users.json"};
    if (users_file_write.is_open())
    {
        users_file_write << std::setw(2) << users_json;
        users_file.close();
    }
}
