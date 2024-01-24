#pragma once
#include <string>

class passed_test
{
public:
    // constructors
    passed_test();
    passed_test(const std::string& a_test_name, size_t a_score);

    // getters
    const std::string& get_test_name();
    size_t get_score() const;

private:
    // test's characteristics 
    std::string test_name;
    size_t score;
};
