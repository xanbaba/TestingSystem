#pragma once
#include <string>

class question_answer
{
public:
    // constructors
    question_answer();
    question_answer(const std::string& a_answer_text, bool a_is_correct);
    
    // getters
    const std::string& get_answer_text();
    bool get_is_correct() const;

private:
    std::string answer_text;
    bool is_correct;
};
