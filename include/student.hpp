// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_STUDENT_HPP_
#define INCLUDE_STUDENT_HPP_

#include <nlohmann/json.hpp>
#include <string>
#include <any>

using nlohmann::json;

namespace st {

struct student_t {
    std::string name;
    std::any group;
    std::any avg;
    std::any debt;
};

auto get_name(const json& j) -> std::string {
        if (j.is_null())
            return nullptr;
        else if (j.is_string())
            return j.get<std::string>();
        else 
            return nullptr;
    }

    auto get_debt(const json& j) -> std::any {
        if (j.is_null())
            return nullptr;
        else if (j.is_string())
            return j.get<std::string>();
        else
            return j.get<std::vector<std::string> >();
    }

    auto get_avg(const json& j) -> std::any {
        if (j.is_null())
            return nullptr;
        else if (j.is_string())
            return j.get<std::string>();
        else if (j.is_number_float())
            return j.get<double>();
        else
            return j.get<std::size_t>();
    }

    auto get_group(const json& j) -> std::any {
        if (j.is_null())
            return nullptr;
        else if (j.is_string())
            return j.get<std::string>();
        else
            return j.get<std::size_t>();
    }

    void from_json(const json& j, student_t& s) {
        s.name = get_name(j.at("name"));
        s.group = get_group(j.at("group"));
        s.avg = get_avg(j.at("avg"));
        s.debt = get_debt(j.at("debt"));
    }

}

#endif // INCLUDE_STUDENT_HPP_
