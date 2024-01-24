#pragma once
#include "user.h"

class log_in_logic
{
public:
    static user* get_user_by_login_password(const std::string& login, const std::string& password);
};
