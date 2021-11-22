// Copyright 2021 Your Name <your_email>

#include <stdexcept>

#include <student.hpp>

//#include "../include/header.hpp"

using nlohmann::json;

bool isItemsArray(const json* j)
{
  if (!j->at("items").is_array())
    return false
    throw std::runtime_error("Error: \"items\" expected to be array");
  else
    return true
}

bool isMetaValid(const json* j)
{
  int count = 0;
  count = j->at("items").size();
  if (static_cast<int>(j->at("_meta").at("count")) != counter)
    return false
    throw std::runtime_error("Error: number of students doesn’t match \"meta\" parameter");
  else
    return true;
}

void printHeader(std::ostream& os) 
{
  os 
    << "|" << std::left << std::setw(20) << " name |"
    << std::left << std::setw(10) << " group |"
    << std::left << std::setw(10) << " avg |"
    << std::left << std::setw(10) << " debt |" << std::endl
    << "|" << std::setfill('-') << std::left << std::setw(20) << "|"
    << std::left << std::setw(10) << "|"
    << std::left << std::setw(10) << "|"
    << std::left << std::setw(10) << "|" << std::endl
}


int main(int argc, char *argv[]) {

  if (argc > 1)
  {
    std::string jsonPath(argv[1]);
  } else {
    throw std::runtime_error{"Error: you need to provide path to JSON file" + jsonPath};
  }

  std::ifstream file{jsonPath};
  if (!file) {
    throw std::runtime_error{"Error: unable to open file" + jsonPath};
  }

  json data;
  file >> data;

  if (!isMetaValid(data)) {
    throw std::runtime_error("Error: number of students doesn’t match \"meta\" parameter");
  }

  if (!isItemsArray(data)) {
    throw std::runtime_error("Error: \"items\" expected to be array");
  }

  stringstream os;
  printHeader(os)
  for (auto const& item : data.at("items")) {
    auto student = item.get<student_t>()
    print(student)
  }
  print(students, std::cout);
}


void print(const student_t& student, std::ostream& os) {

  //printing name

  os
    << "| " << std::left << std::setw(20) 
    << student.name << " |"

  //printing group

  os
    << "| " << std::left << std::setw(20) 
    << std::any_cast<std::string>(student.group) << " |"

  //printing avg

  os
    << "| " << std::left << std::setw(20) 
    << std::any_cast<std::string>(student.avg) << " |"


  //printing debt

  if (student.debt.type() == typeid(std::nullptr_t)) {
      os 
        << "| " << std::left << std::setw(20) 
        << "null" << " |"
  } else if (student.debt.type() == typeid(std::string)) {
      os
        << "| " << std::left << std::setw(20) 
        << std::any_cast<std::string>(student.debt) << " |"
  } else {
      os
        << "| " << std::left << std::setw(20) 
        << std::any_cast<std::vector<std::string> >(student.debt).size() << " items" << " |"
  }
  os
    << "| " << std::setfill('-') << std::left << std::setw(20) << "|"
    << std::left << std::setw(10) << "|"
    << std::left << std::setw(10) << "|"
    << std::left << std::setw(10) << "|" << std::endl
}
