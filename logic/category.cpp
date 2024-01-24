#include "category.h"

category::category()
= default;

category::category(const std::string& a_category_name, const std::vector<test>& a_tests_list) :
    category_name(a_category_name), tests_list(a_tests_list)
{
}

const std::string& category::get_category_name()
{
    return category_name;
}

std::vector<test>& category::get_tests_list()
{
    return tests_list;
}
