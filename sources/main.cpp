// Copyright 2021 Your Name <your_email>

#include <stdexcept>

#include <student.hpp>
#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>

using nlohmann::json;

bool isItemsArray(const json& j)
{
  if (!j.at("items").is_array()) {

    return false;
    throw std::runtime_error("Error: \"items\" expected to be array");
  }
  else {
    return true;
  }
}

bool isMetaValid(const json& j)
{
  int count = 0;
  count = j.at("items").size();
  
  if (static_cast<int>(j.at("_meta").at("count")) != count) {
    return false;
    throw std::runtime_error("Error: number of students doesn’t match \"meta\" parameter");
  }
  else {
    return true;
  }
}

void printHeader(std::ostream& os) 
{
  os 
    << "|" << std::left << std::setw(20) << " name" << " |"
    << std::left << std::setw(20) << " group" << " |"
    << std::left << std::setw(20) << " avg" << " |"
    << std::left << std::setw(20) << " debt" << " |" << std::endl
    << std::setfill('-') << std::left << std::setw(22) << "|"
    << std::left << std::setw(22) << "|"
    << std::left << std::setw(22) << "|"
    << std::left << std::setw(22) << "|" << "|" << std::endl;
}


void printStudent(const st::student_t& student, std::ostream& os) {

  //printing name
  os << std::setfill(' ');
  os
    << "| " << std::left << std::setw(20) 
    << student.name << "|";

  //printing group

  if (student.group.type() == typeid(std::nullptr_t)) {
      os 
        << std::left << std::setw(20) 
        << " null" << " |";
  } else if (student.group.type() == typeid(std::string)) {
      os
        << " " << std::left << std::setw(20) 
        << std::any_cast<std::string>(student.group) << "|";
  } else {
    //std::cout << student.group.type().name();
      os
        << " " << std::left << std::setw(20) 
        << std::any_cast<unsigned long>(student.group) << "|";
  }

  //printing avg

  if (student.avg.type() == typeid(std::nullptr_t)) {
      os 
        << std::left << std::setw(20) 
        << " null" << " |";
  } else if (student.avg.type() == typeid(std::string)) {
      os
        << " " << std::left << std::setw(20) 
        << std::any_cast<std::string>(student.avg) << "|";
  } else if (student.avg.type() == typeid(double)) {
      os
        << " " << std::left << std::setw(20) 
        << std::any_cast<double>(student.avg) << "|";
  } else {
    os
      << " " << std::left << std::setw(20) 
      << std::any_cast<unsigned long>(student.avg) << "|";
  }

  //printing debt

  if (student.debt.type() == typeid(std::nullptr_t)) {
      os 
        << std::left << std::setw(20) 
        << " null" << " |";
  } else if (student.debt.type() == typeid(std::string)) {
      os
        << " " << std::left << std::setw(20) 
        << std::any_cast<std::string>(student.debt) << "|";
  } else {
      os
        << " " << std::left << std::setw(20) 
        << std::to_string(std::any_cast<std::vector<std::string> >(student.debt).size()) + " items" << "|";
  }
  os
    << std::endl << std::setfill('-') << std::left << std::setw(22) << "|"
    << std::left << std::setw(22) << "|"
    << std::left << std::setw(22) << "|"
    << std::left << std::setw(22) << "|" << "|" << std::endl;
}

void processJSON(const std::string& jsonPath, std::stringstream& os) {

  std::ifstream file{jsonPath};
  if (!file) {
    throw std::runtime_error{"Error: unable to open file " + jsonPath};
  }
  json data;
  file >> data;

  if (!isItemsArray(data)) {
    throw std::runtime_error("Error: \"items\" expected to be array");
  } 

  if (!isMetaValid(data)) {
    throw std::runtime_error("Error: number of students doesn’t match \"meta\" parameter");
  }

  printHeader(os);
  for (auto const& item : data.at("items")) {
    st::student_t student = item.get<st::student_t>();
    printStudent(student, os);
  }
  std::cout << os.str();
}


