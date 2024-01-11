#include "log_on_logic.h"

#include <fstream>

#include "user.h"

bool log_on_logic::is_login_correct()
{
    std::ifstream users("DataBase/users.bin", std::ios::out | std::ios::binary);
    if (users.is_open())
    {
        std::vector<user> users_vector;
        
        users.close();
    }
}

void log_on_logic::add_user()
{
}
