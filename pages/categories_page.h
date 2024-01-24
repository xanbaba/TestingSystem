#pragma once
#include "../logic/category.h"
#include "../logic/key_detector.h"
#include "../single_include/nlohmann/json.hpp"
#include "../logic/user.h"

class categories_page
{
public:
    static void show_page(user& base_user);
private:
    static void render_page(std::vector<category>& categories);
    static void set_current_field(key button, const std::vector<category>& categories);
    inline static int current_field = 0;
};
