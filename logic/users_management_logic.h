#pragma once
#include <string>
#include <vector>

class users_management_logic
{
public:
    static std::vector<std::string> get_users_logins();
    static void change_user(const std::string& user_login, const std::string& new_login, const std::string& new_password);
};
