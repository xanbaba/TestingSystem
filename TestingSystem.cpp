#include <iostream>

#include "pages/entrance_page.h"
#include "pages/log_in_page.h"
#include "pages/log_on_page.h"
#include "logic/sha1.hpp"

int main(int argc, char* argv[])
{
    entrance_page page_entrance_page;
    int entrance_page_choice = page_entrance_page.show_page();
    if (entrance_page_choice == 0)
    {
        log_in_page::show_page();
    }
     else if (entrance_page_choice == 1)
    {
        log_on_page::show_page();
    }
    std::cin.get();
    return 0;
}
