#include "users_management_page.h"

#include <iostream>

#include "log_on_page.h"
#include "../logic/log_on_logic.h"
#include "../logic/users_management_logic.h"

users_management_page::users_management_page()
{
    users_logins = users_management_logic::get_users_logins();
}


void users_management_page::show_page()
{
    render_page();
    while (true)
    {
        const auto button = key_detector::detect();
        if (button == key::enter)
        {
            if (current_field == static_cast<int>(users_logins.size() + fields.size() - 1))
            {
                return;
            }
            if (current_field == static_cast<int>(users_logins.size() + fields.size() - 2))
            {
                log_on_page::show_page();
                users_logins = users_management_logic::get_users_logins();
                render_page();
                continue;
            }
            change_user(users_logins[current_field]);
            users_logins = users_management_logic::get_users_logins();
            render_page();
        }
        if (button != key::none)
        {
            set_current_field(button);
            render_page();
        }
    }
}

void users_management_page::render_page() const
{
    system("cls");
    int field_number{};
    for (auto& user_login : users_logins)
    {
        std::cout << user_login << ' ';
        if (field_number == current_field)
        {
            std::cout << '*';
        }
        std::cout << '\n';
        ++field_number;
    }
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

void users_management_page::set_current_field(key button) const
{
    if (button == key::down)
    {
        ++current_field;
        if (current_field == static_cast<int>(fields.size() + users_logins.size()))
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

void users_management_page::change_user(const std::string& user_login)
{
    system("cls");
    std::string new_login;
    std::string new_password;
    while (true)
    {
        std::cout << "Enter new login: ";
        std::cin >> new_login;
        if (log_on_logic::is_login_unique(new_login))
        {
            break;
        }
        std::cout << "This login is already taken. Try another one\n\n";
    }
    std::cout << "Enter new password: ";
    std::cin >> new_password;
    users_management_logic::change_user(user_login, new_login, new_password);
}
