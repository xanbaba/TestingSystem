#include "question.h"

question::question()
= default;

question::question(const std::string& a_question_text, const std::vector<question_answer>& a_question_answer_list) :
    question_text(a_question_text), question_answers_list(a_question_answer_list)
{
}

const std::string& question::get_question_text()
{
    return question_text;
}

std::vector<question_answer>& question::get_question_answers_list()
{
    return question_answers_list;
}
