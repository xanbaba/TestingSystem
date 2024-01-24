#include "stopped_test.h"

stopped_test::stopped_test(size_t a_id, size_t a_question_number, size_t a_correct_answers) : id(a_id),
    question_number(a_question_number), correct_answers(a_correct_answers)
{
}

size_t stopped_test::get_id() const
{
    return id;
}

size_t stopped_test::get_question_number() const
{
    return question_number;
}

size_t stopped_test::get_correct_answers() const
{
    return correct_answers;
}
