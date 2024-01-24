#include "categories_page.h"

#include <iostream>

#include "tests_page.h"
#include "../logic/category_logic.h"
#include "../logic/key_detector.h"

void categories_page::set_current_field(key button, const std::vector<category>& categories)
{
    if (button == key::down)
    {
        ++current_field;
        if (current_field == static_cast<int>(categories.size()) + 1)
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

void categories_page::show_page(user& base_user)
{
    auto categories = category_logic::get_categories();
    render_page(categories);
    while (true)
    {
        auto button = key_detector::detect();
        if (button == key::enter)
        {
            if (current_field == static_cast<int>(categories.size()))
            {
                return;
            }
            tests_page::show_page(base_user, categories[current_field]);
        }
        if (button != key::none)
        {
            set_current_field(button, categories);
            render_page(categories);
        }
    }
}

void categories_page::render_page(std::vector<category>& categories)
{
    system("cls");
    for (int i = 0; i < static_cast<int>(categories.size()); ++i)
    {
        std::cout << categories[i].get_category_name() << ' ';
        if (i == current_field)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
    std::cout << "exit ";
    if (static_cast<int>(categories.size()) == current_field)
    {
        std::cout << '*';
    }
    std::cout << '\n';
}
