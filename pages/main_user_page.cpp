#include "main_user_page.h"
#include "../logic/key_detector.h"

#include <iostream>

#include "categories_page.h"
#include "passed_tests_page.h"
#include "stopped_test_page.h"

void main_user_page::show_page(user& base_user) 
{
    render_page();
    while (true)
    {
        auto button = key_detector::detect();
        if (button == key::enter)
        {
            if (current_field == 0)
            {
                categories_page::show_page(base_user);
            }
            else if (current_field == 1)
            {
                passed_tests_page::show_page(base_user);
            }
            else if (current_field == 2)
            {
                stopped_test_page::show_page(base_user);
            }
            else if (current_field == static_cast<int>(fields.size()) - 1)
            {
                return;
            }
            render_page();
        }
        if (button != key::none)
        {
            set_current_field(button);
            render_page();
        }
    }
}

void main_user_page::render_page()
{
    system("cls");
    for (int i = 0; i < static_cast<int>(fields.size()); ++i)
    {
        std::cout << fields[i] << ' ';
        if (i == current_field)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

void main_user_page::set_current_field(key button)
{
    if (button == key::down)
    {
        ++current_field;
        if (current_field == static_cast<int>(fields.size()))
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
