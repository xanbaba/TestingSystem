#pragma once
#include <string>
#include <vector>

#include "../logic/key_detector.h"

class main_admin_page
{
public:
    static void show_page();
private:
    static void render_page();
    static void set_current_field(key button);
    inline static int current_field = 0;
    inline static std::vector<std::string> fields {"users management", "statistics", "tests management", "exit"};
};
