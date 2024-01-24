#pragma once
#include <string>
#include <vector>

#include "test.h"

class category
{
public:
    // constructors
    category();
    category(const std::string& a_category_name, const std::vector<test>& a_tests_list);

    // getters
    const std::string& get_category_name();
    std::vector<test>& get_tests_list();
private:
    std::string category_name;
    std::vector<test> tests_list;
};
