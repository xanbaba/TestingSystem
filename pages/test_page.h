#pragma once
#include "../logic/test.h"
#include "../logic/test_logic.h"
#include "../logic/category.h"

class test_page
{
public:
    static void start_test(user& base_user, test& test_object, test_logic& logic_tester, size_t question_index = 0);
private:
    static bool render_question(user& base_user, question& question_object, size_t question_index, test_logic& logic_tester);
    
};
