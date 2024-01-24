#pragma once
#include "category.h"
#include "question.h"
#include "stopped_test.h"
#include "test.h"
#include "user.h"

class test_logic
{
public:
    ~test_logic();
    test_logic(test& a_test_object);
    test_logic(const stopped_test& a_stopped_test_object);

    void run_checker(size_t question_index, size_t answer_index);
    bool is_answer_valid(size_t question_index, int answer_index) const;
    size_t get_grade() const;
    void save_to_user(user& base_user) const;
    bool is_stopping_test(size_t answer_index, size_t question_index) const;
    void stop_test(user& base_user, size_t question_index) const;
private:
    int correct_answers;
    int question_amount;
    test* test_object;
    bool is_stopped;
};
