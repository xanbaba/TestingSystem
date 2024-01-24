#include "log_in_page.h"

#include <iostream>
#include <string>
#include <Windows.h>

#include "../logic/log_in_logic.h"

user log_in_page::show_page()
{
    system("cls");
    
    std::string login, password, fio, phone_number;
    
    std::cout << "Log in process. Press any button to continue\n";
    std::cin.get();

    user* login_user;
    
    while (true)
    {
        std::cout << "Enter login: ";
        std::getline(std::cin, login);
        std::cout << "Enter password: ";
        std::getline(std::cin, password);
        
        login_user = log_in_logic::get_user_by_login_password(login, password);
        if (login_user == nullptr)
        {
            std::cout << "Login or password is incorrect\n\n";
            Sleep(1500);
            continue;
        }
        break;
    }

    std::cout << "Login has completed successfully \n";
    Sleep(1500);
    
    auto copy_user = *login_user;
    delete login_user;
    return copy_user;
}
