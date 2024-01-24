#include "passed_tests_page.h"

#include <iostream>

#include "../logic/key_detector.h"

void passed_tests_page::show_page(user& base_user)
{
    system("cls");
    std::cout << "   name            score \n";
    int test_number = 1;
    for (auto& passed_test : base_user.get_passed_tests())
    {
        std::cout << test_number << ") " << passed_test.get_test_name() << "            " << passed_test.get_score() << '\n';
        ++test_number;
    }
    std::cout << "\n\nPress enter to exit";
    while (key_detector::detect() != key::enter)
    {
    }
}
