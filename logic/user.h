#pragma once
#include <string>
#include <vector>

#include "passed_test.h"
#include "stopped_test.h"

class user
{
public:
    user(const std::string& a_login,
         const std::string& a_password,
         const std::string& a_fio,
         const std::string& a_phone_number,
         const std::vector<passed_test>& a_passed_tests,
         const std::vector<stopped_test>& a_stopped_tests,
         bool a_is_admin)
    {
        login = a_login;
        password = a_password;
        fio = a_fio;
        phone_number = a_phone_number;
        passed_tests = a_passed_tests;
        stopped_tests = a_stopped_tests;
        is_admin = a_is_admin;
        
    }

    std::string login,
                password,
                fio,
                phone_number;

    std::vector<passed_test> passed_tests;
    std::vector<stopped_test> stopped_tests;
    bool is_admin;
};
