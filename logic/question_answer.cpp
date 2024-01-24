#include "question_answer.h"

question_answer::question_answer() : is_correct(false)
{
}

question_answer::question_answer(const std::string& a_answer_text, bool a_is_correct) :
    answer_text(a_answer_text), is_correct(a_is_correct)
{
}

const std::string& question_answer::get_answer_text()
{
    return answer_text;
}

bool question_answer::get_is_correct() const
{
    return is_correct;
}
