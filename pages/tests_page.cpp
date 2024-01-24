#include "tests_page.h"

#include <iostream>

#include "test_page.h"
#include "../logic/category_logic.h"

void tests_page::set_current_field(key button, std::vector<test>& tests)
{
    if (button == key::down)
    {
        ++current_field;
        if (current_field == static_cast<int>(tests.size()) + 1)
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

void tests_page::show_page(user& base_user, category& tests_category)
{
    auto tests_list = tests_category.get_tests_list();
    render_page(tests_list);
    while (true)
    {
        auto button = key_detector::detect();
        if (button == key::enter)
        {
            if (current_field == static_cast<int>(tests_list.size()))
            {
                return;
            }
            test_logic logic_tester{tests_list[current_field]};
            test_page::start_test(base_user, tests_list[current_field], logic_tester);
        }
        if (button != key::none)
        {
            set_current_field(button, tests_list);
            render_page(tests_list);
        }
    }
}

void tests_page::render_page(std::vector<test>& tests)
{
    system("cls");
    for (int i = 0; i < static_cast<int>(tests.size()); ++i)
    {
        std::cout << tests[i].get_name() << ' ';
        if (i == current_field)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
    std::cout << "exit ";
    if (static_cast<int>(tests.size()) == current_field)
    {
        std::cout << '*';
    }
    std::cout << '\n';
}
