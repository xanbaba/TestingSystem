#include "log_on_logic.h"

#include <fstream>

#include "sha1.hpp"
#include "../single_include/nlohmann/json.hpp"

using json = nlohmann::json;

bool log_on_logic::is_login_unique(const std::string& login)
{
    std::ifstream users("data_base/users.json");
    if (users.is_open())
    {
        json users_json = json::parse(users);
        for (auto user_object : users_json)
        {
            if (user_object["login"] == login)
            {
                return false;
            }
        }
        users.close();
    }

    return true;
}

void log_on_logic::add_user(const std::string& login,
                            const std::string& password,
                            const std::string& fio,
                            const std::string& phone_number
)
{
    json users_json;
    
    std::ifstream users_read("data_base/users.json");
    if (users_read.is_open())
    {
        json new_user;
        users_json = json::parse(users_read);
        bool is_admin = false;
        if (users_json.empty())
        {
            is_admin = true;
        }

        // Password encrypt
        SHA1 checksum;
        checksum.update(password);
        auto password_encrypted = checksum.final();

        new_user["login"] = login;
        new_user["password"] = password_encrypted;
        new_user["fio"] = fio;
        new_user["phone_number"] = phone_number;
        new_user["is_admin"] = is_admin;
        new_user["passed_tests"] = json::array();
        new_user["stopped_tests"] = json::array();

        users_json.push_back(new_user);
        
        users_read.close();
    }

    std::ofstream users_write("data_base/users.json");
    if (users_write)
    {
        users_write << std::setw(2) << users_json;
        users_write.close();
    }
}
