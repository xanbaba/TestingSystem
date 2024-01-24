#pragma once
#include <vector>

#include "../logic/category.h"
#include "../logic/key_detector.h"
#include "../logic/test.h"
#include "../logic/user.h"

class tests_page
{
public:
    static void show_page(user& base_user, category& tests_category);
private:
    static void render_page(std::vector<test>& tests);
    static void set_current_field(key button, std::vector<test>& tests);
    
    inline static int current_field = 0;
};
