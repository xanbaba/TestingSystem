#include "stopped_test_logic.h"

#include <fstream>

#include "category_logic.h"
#include "../single_include/nlohmann/json.hpp"

using json = nlohmann::json;

test stopped_test_logic::get_test_by_id(const size_t id)
{
    std::ifstream tests_file{"data_base/tests.json"};
    if (tests_file.is_open())
    {
        auto categories = category_logic::get_categories();
        for (auto& category_object : categories)
        {
            for (auto& test_object : category_object.get_tests_list())
            {
                if (id == static_cast<size_t>(test_object.get_id()))
                {
                    return test_object;
                }
            }
        }
        tests_file.close();
    }
    return test{"", {}, -1};
}
