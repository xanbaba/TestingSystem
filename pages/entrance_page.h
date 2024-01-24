#pragma once
#include <string>
#include <vector>

#include "../logic/user.h"
#include "../logic/key_detector.h"

class entrance_page
{
public:
    static user load_user();
private:
    std::vector<std::string> fields {"log in", "log on"};
    int selected_field = 0;

    void render_page();
    void set_current_field(key button);
    int show_page();
};
