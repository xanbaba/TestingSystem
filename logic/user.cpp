#include "user.h"

user::user(): user("", "", "", "", false)
{
}

user::user(const std::string& a_login,
           const std::string& a_password,
           const std::string& a_fio,
           const std::string& a_phone_number,
           bool a_is_admin,
           const std::vector<passed_test>& a_passed_tests,
           const std::vector<stopped_test>& a_stopped_tests) :
    login(a_login),
    password(a_password),
    fio(a_fio),
    phone_number(a_phone_number),
    is_admin(a_is_admin),
    passed_tests(a_passed_tests),
    stopped_tests(a_stopped_tests)
{
}

const std::string& user::get_login()
{
    return login;
}

const std::string& user::get_password()
{
    return password;
}

const std::string& user::get_fio()
{
    return fio;
}

const std::string& user::get_phone_number()
{
    return phone_number;
}

bool user::get_is_admin()
{
    return is_admin;
}

std::vector<passed_test>& user::get_passed_tests()
{
    return passed_tests;
}

std::vector<stopped_test>& user::get_stopped_tests()
{
    return stopped_tests;
}
