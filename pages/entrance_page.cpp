#include "entrance_page.h"
#include <conio.h>
#include <iostream>

#include "log_in_page.h"
#include "log_on_page.h"

user entrance_page::load_user()
{
    entrance_page page_entrance_page;
    const int entrance_page_choice = page_entrance_page.show_page();

    user entered_user;
    
    if (entrance_page_choice == 0)
    {
        entered_user = log_in_page::show_page();
    }
    else if (entrance_page_choice == 1)
    {
        log_on_page::show_page();
        entered_user = log_in_page::show_page();
    }

    return entered_user;
}

int entrance_page::show_page()
{
    render_page();
    while (true)
    {
        auto button = key_detector::detect();
        if (button == key::enter)
        {
            system("cls");
            break;
        }
        if (button != key::none)
        {
            set_current_field(button);
            render_page();
        }
    }
    return selected_field;
    /*while (true)
    {
        if (_kbhit())
        {
            int button = _getch();
            std::cout << button << '\n';
        }
    }*/
}

void entrance_page::render_page()
{
    system("cls");
    for (int i = 0; i < static_cast<int>(fields.size()); ++i)
    {
        std::cout << fields[i] << ' ';
        if (selected_field == i)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

void entrance_page::set_current_field(key button)
{
    if (button == key::down)
    {
        ++selected_field;
        if (selected_field == static_cast<int>(fields.size()))
        {
            --selected_field;
        }
        return;
    }
    if (button == key::up)
    {
        --selected_field;
        if (selected_field < 0)
        {
            ++selected_field;
        }
    }
}
