// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_

#include <string>
#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <any>

struct student_t {
    std::string name;
    std::any group;
    std::any avg;
    std::any debt;
} 

#endif // INCLUDE_EXAMPLE_HPP_
