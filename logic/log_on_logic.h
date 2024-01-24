#pragma once
#include <string>

class log_on_logic
{
public:
    static bool is_login_unique(const std::string& login);
    static void add_user(const std::string& login, const std::string& password, const std::string& fio, const std::string& phone_number);
};
