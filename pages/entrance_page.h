#pragma once
#include <string>
#include <vector>

enum class key
{
    none = 0,
    up = 72,
    down = 80,
    enter = 13
};

class entrance_page
{
public:
    int show_page();
private:
    std::vector<std::string> fields {"log in", "log on"};
    int selected_field = 0;

    void render_page();
    key key_detector();
    void set_current_field(key button);
};
