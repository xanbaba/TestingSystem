#pragma once
#include "../logic/user.h"

enum class key;

class main_user_page
{
public:
    static void show_page(user& base_user);
private:
    static void render_page();
    inline static std::vector<std::string> fields{"test categories", "passed tests", "stopped tests", "exit"};
    static void set_current_field(key button);
    
    inline static int current_field = 0;
};
