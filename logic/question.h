#pragma once
#include <string>
#include <vector>

#include "question_answer.h"

class question
{
public:
    // constructors
    question();
    question(const std::string& a_question_text, const std::vector<question_answer>& a_question_answer_list);

    // getters
    const std::string& get_question_text();
    std::vector<question_answer>& get_question_answers_list();
private:
    std::string question_text;
    std::vector<question_answer> question_answers_list;
};
