// Copyright 2021 Your Name <your_email>
#define TEST_CPP_
#ifdef TEST_CPP_

#include <stdexcept>
#include <gtest/gtest.h>
#include <json_util.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;

using json = nlohmann::json;

TEST(empty, json)
{

}

TEST(global, json)
{
    std::stringstream os;
    processJSON("../tests/test1.json", os);
    ASSERT_EQ("| name                | group               | avg                 | debt                |\n"
        "|---------------------|---------------------|---------------------|---------------------|\n"
        "| Ivanov Petr         | null                | 4.25                | 123                 |\n"
        "|---------------------|---------------------|---------------------|---------------------|\n"
        "| Sidorov Ivan        | 31                  | 4                   | C++                 |\n"
        "|---------------------|---------------------|---------------------|---------------------|\n"
    , os.str());

}

TEST(itemsNotArray, json)
{
    std::stringstream os;
    EXPECT_THROW(processJSON("../tests/test2.json", os), std::runtime_error);
}

TEST(wrongMeta, json) {
    std::stringstream os;
    EXPECT_THROW(processJSON("../tests/test3.json", os), std::runtime_error);
}

TEST(global2, json)
{
    std::stringstream os;
    processJSON("../tests/test4.json", os);
    ASSERT_EQ("| name                | group               | avg                 | debt                |\n"
    "|---------------------|---------------------|---------------------|---------------------|\n"
    "| Ivan Ivanov         | 1                   | 4.25                | null                |\n"
    "|---------------------|---------------------|---------------------|---------------------|\n"
    "| Sidorov Ivan        | 31                  | 4                   | C++                 |\n"
    "|---------------------|---------------------|---------------------|---------------------|\n"
    "| Pertov Nikita       | IU8-31              | 3.33                | 3 items             |\n"
    "|---------------------|---------------------|---------------------|---------------------|\n"
    , os.str());
}

#endif // TEST_CPP_