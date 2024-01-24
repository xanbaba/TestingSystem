#include "test.h"

test::test(const std::string& a_name, const std::vector<question>& a_questions_list, int a_id) :
    name(a_name),
    questions_list(a_questions_list),
    id(a_id)
{
}

const std::string& test::get_name() const
{
    return name;
}

std::vector<question>& test::get_questions_list()
{
    return questions_list;
}

int test::get_id() const
{
    return id;
}
