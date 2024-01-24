#include "test_page.h"

#include <iostream>

#include "../logic/key_detector.h"


void test_page::start_test(user& base_user, test& test_object, test_logic& logic_tester, size_t question_index)
{
    if (question_index == test_object.get_questions_list().size())
    {
        logic_tester.save_to_user(base_user);
        std::cout << "Your score is: " << logic_tester.get_grade() << '\n';
        std::cout << "Press enter to exit" << '\n';
        key button = key::none;
        while (button != key::enter)
        {
            button = key_detector::detect();
        }
        return;
    }
    if (!render_question(base_user, test_object.get_questions_list()[question_index], question_index, logic_tester))
    {
        return;
    }
    start_test(base_user, test_object, logic_tester, question_index + 1);
}

bool test_page::render_question(user& base_user, question& question_object, size_t question_index, test_logic& logic_tester)
{
    system("cls");
    std::cout << question_index + 1 << ") " << question_object.get_question_text() << '\n';
    auto answers_list = question_object.get_question_answers_list();
    for (size_t i = 0; i < answers_list.size(); ++i)
    {
        std::cout << "    " << i + 1 << ") " << answers_list[i].get_answer_text() << '\n';
    }
    std::cout << "    " << answers_list.size() + 1 << ") " << "stop the test (you can continue later)" << '\n';

    int answer_index;
    
    std::cout << "Enter the number of your answer: ";
    std::cin >> answer_index;
    while (!logic_tester.is_answer_valid(question_index, answer_index))
    {
        std::cout << "The answer is invalid try again\n";
        std::cout << "Enter the number of your answer: ";
        std::cin >> answer_index;
    }
    if (logic_tester.is_stopping_test(answer_index, question_index))
    {
        logic_tester.stop_test(base_user, question_index);
        return false;
    }
    logic_tester.run_checker(question_index, answer_index);
    return true;
}
