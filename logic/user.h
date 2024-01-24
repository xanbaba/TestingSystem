#pragma once
#include <string>
#include <vector>

#include "passed_test.h"
#include "stopped_test.h"

class user
{
public:
    // constructors
    user();
    user(const std::string& a_login,
         const std::string& a_password,
         const std::string& a_fio,
         const std::string& a_phone_number,
         bool a_is_admin,
         const std::vector<passed_test>& a_passed_tests = {},
         const std::vector<stopped_test>& a_stopped_tests = {});

    // getters
    const std::string& get_login();
    const std::string& get_password();
    const std::string& get_fio();
    const std::string& get_phone_number();
    bool get_is_admin();
    std::vector<passed_test>& get_passed_tests();
    std::vector<stopped_test>& get_stopped_tests();

private:
    std::string login,
                password,
                fio,
                phone_number;

    bool is_admin;
    std::vector<passed_test> passed_tests;
    std::vector<stopped_test> stopped_tests;
};
