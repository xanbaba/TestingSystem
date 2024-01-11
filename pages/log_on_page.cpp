#include "log_on_page.h"

#include <iostream>
#include <string>

void log_on_page::show_page()
{
    std::string login, password, fio, phone_number;
    std::cout << "Registration process. Press any button to continue\n";
    std::cin.get();
    std::cout << "Create login: ";
    std::getline(std::cin, login);
    std::cout << "Create password: ";
    std::getline(std::cin, password);
    std::cout << "Enter your name, surname, and father's name: ";
    std::getline(std::cin, fio);
    std::cout << "Enter your phone number: ";
    std::getline(std::cin, phone_number);

    // TODO: send data to log_on_logic class

    std::cout << "Registration has completed successfully \n";
}
