#include "stopped_test_page.h"

#include <iostream>

#include "../pages/test_page.h"
#include "../logic/stopped_test_logic.h"
#include "../logic/key_detector.h"

void stopped_test_page::show_page(user& base_user)
{
    std::vector<test> stopped_tests;
    for (auto& stopped_test_object : base_user.get_stopped_tests())
    {
        stopped_tests.push_back(stopped_test_logic::get_test_by_id(stopped_test_object.get_id()));
    }
    render_page(stopped_tests);
    while (true)
    {
        auto button = key_detector::detect();
        if (button == key::enter)
        {
            if (current_field == static_cast<int>(stopped_tests.size()))
            {
                return;
            }
            auto selected_test = base_user.get_stopped_tests()[current_field];
            test_logic logic_tester{selected_test};
            test_page::start_test(base_user, stopped_tests[current_field], logic_tester,
                                  selected_test.get_question_number());
            stopped_tests = {};
            for (auto& stopped_test_object : base_user.get_stopped_tests())
            {
                stopped_tests.push_back(stopped_test_logic::get_test_by_id(stopped_test_object.get_id()));
            }
            render_page(stopped_tests);
        }
        if (button != key::none)
        {
            set_current_field(button, stopped_tests);
            render_page(stopped_tests);
        }
    }
}

void stopped_test_page::render_page(const std::vector<test>& stopped_tests)
{
    system("cls");
    for (int i = 0; i < static_cast<int>(stopped_tests.size()); ++i)
    {
        std::cout << stopped_tests[i].get_name() << ' ';
        if (i == current_field)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
    std::cout << "exit ";
    if (static_cast<int>(stopped_tests.size()) == current_field)
    {
        std::cout << '*';
    }
    std::cout << '\n';
}

void stopped_test_page::set_current_field(key button, const std::vector<test>& stopped_tests)
{
    if (button == key::down)
    {
        ++current_field;
        if (current_field == static_cast<int>(stopped_tests.size()) + 1)
        {
            --current_field;
        }
        return;
    }
    if (button == key::up)
    {
        --current_field;
        if (current_field < 0)
        {
            ++current_field;
        }
    }
}
