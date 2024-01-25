#pragma once

#include <string>
#include <vector>

#include "../logic/key_detector.h"

class users_management_page
{
public:
    users_management_page();
    void show_page();
private:
    void render_page() const;
    void set_current_field(key button) const;
    void change_user(const std::string& user_login);
    inline static int current_field = 0;
    inline static std::vector<std::string> fields{"add user", "exit"};
    std::vector<std::string> users_logins;
};
