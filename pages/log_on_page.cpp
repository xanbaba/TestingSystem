#include "log_on_page.h"

#include <iostream>
#include <string>
#include <Windows.h>

#include "../logic/log_on_logic.h"

void log_on_page::show_page()
{
    system("cls");
    
    std::string login, password, fio, phone_number;
    
    std::cout << "Registration process. Press any button to continue\n";
    std::cin.get();

    while (true)
    {
        std::cout << "Create login: ";
        std::getline(std::cin, login);
        if (!log_on_logic::is_login_unique(login))
        {
            std::cout << "This login is already taken\n\n\n";
            Sleep(1500);
            continue;
        }
        break;
    }
    std::cout << "Create password: ";
    std::getline(std::cin, password);
    
    std::cout << "Enter your name, surname, and father's name: ";
    std::getline(std::cin, fio);
    
    std::cout << "Enter your phone number: ";
    std::getline(std::cin, phone_number);
    

    log_on_logic::add_user(login, password, fio, phone_number);

    std::cout << "Registration has completed successfully \n";
    Sleep(1500);
}
