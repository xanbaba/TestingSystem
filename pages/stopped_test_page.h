#pragma once
#include "../logic/test.h"
#include "../logic/user.h"
#include "../logic/key_detector.h"

class stopped_test_page
{
public:
    static void show_page(user& base_user);

private:
    static void set_current_field(key button, const std::vector<test>& stopped_tests);
    inline static int current_field = 0;
    static void render_page(const std::vector<test>& stopped_tests);
};
