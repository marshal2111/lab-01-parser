// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_STUDENT_HPP_
#define INCLUDE_STUDENT_HPP_

#include <nlohmann/json.hpp>
#include <string>
#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <any>

namespace st {

struct student_t {
    std::string name;
    std::any group;
    std::any avg;
    std::any debt;
};

}

#endif // INCLUDE_STUDENT_HPP_
