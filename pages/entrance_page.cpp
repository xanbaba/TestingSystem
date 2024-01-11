#include "entrance_page.h"
#include <conio.h>
#include <iostream>

int entrance_page::show_page()
{
    render_page();
    while (true)
    {
        auto button = key_detector();
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

key entrance_page::key_detector()
{
    if (_kbhit())
    {
        key button = static_cast<key>(_getch());
        switch (button) {
        case key::none:
        case key::up:
        case key::down:
        case key::enter:
            return button;
        }
    }
    return key::none;
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
