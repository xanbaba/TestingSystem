#include "main_admin_page.h"

#include <iostream>

#include "users_management_page.h"

void main_admin_page::show_page()
{
    render_page();
    while (true)
    {
        const auto button = key_detector::detect();
        if (button == key::enter)
        {
            if (current_field == static_cast<int>(fields.size() - 1))
            {
                return;
            }
            if (current_field == 0)
            {
                users_management_page{}.show_page();
            }
            else if (current_field == 1)
            {
                // TODO: statistics
            }
            else if (current_field == 2)
            {
                // TODO: tests management
            }
        }
        if (button != key::none)
        {
            set_current_field(button);
            render_page();
        }
    }
}

void main_admin_page::render_page()
{
    system("cls");
    int field_number{};
    for (auto& field : fields)
    {
        std::cout << field << ' ';
        if (field_number == current_field)
        {
            std::cout << '*';
        }
        std::cout << '\n';
        ++field_number;
    }
}

void main_admin_page::set_current_field(key button)
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
