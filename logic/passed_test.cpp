#include "passed_test.h"

passed_test::passed_test() : score()
{
}

passed_test::passed_test(const std::string& a_test_name, size_t a_score) :
    test_name(a_test_name), score(a_score)
{
}

const std::string& passed_test::get_test_name()
{
    return test_name;
}

size_t passed_test::get_score() const
{
    return score;
}
