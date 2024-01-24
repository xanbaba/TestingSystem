#pragma once

class stopped_test
{
public:
    // constructor
    stopped_test(size_t a_id, size_t a_question_number, size_t a_correct_answers);

    // methods
    size_t get_id() const;
    size_t get_question_number() const;
    size_t get_correct_answers() const;
private:
    size_t id;
    size_t question_number;
    size_t correct_answers;
};
