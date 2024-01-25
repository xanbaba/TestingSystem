#include "pages/entrance_page.h"
#include "pages/main_admin_page.h"
#include "pages/main_user_page.h"

int main(int argc, char* argv[])
{
    auto base_user = entrance_page::load_user();
    if (base_user.get_is_admin())
    {
        main_admin_page::show_page();
    }
    else
    {
        main_user_page::show_page(base_user);
    }
    return 0;
}
