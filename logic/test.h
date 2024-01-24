#pragma once
#include <string>
#include <vector>

#include "question.h"

class test
{
public:
    // constructors
    test(const std::string& a_name, const std::vector<question>& a_questions_list, int a_id);

    // getters
    const std::string& get_name() const;
    std::vector<question>& get_questions_list();
    int get_id() const;
private:
    std::string name;
    std::vector<question> questions_list;
    int id;
    
};
