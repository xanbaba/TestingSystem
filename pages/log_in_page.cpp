#include "log_in_page.h"

#include <iostream>
#include <string>

void log_in_page::show_page()
{
    std::string login, password, fio, phone_number;
    std::cout << "Log in process. Press any button to continue\n";
    std::cin.get();
    std::cout << "Enter login: ";
    std::getline(std::cin, login);
    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    // TODO: send data to log_in_logic class

    std::cout << "Login has completed successfully \n";
}
