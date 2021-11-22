#include "../sources/main.cpp"
#include <student.hpp>
#include <stdexcept>
#include <fstream>

using namespace std;

using nlohmann::json;

int main(int argc, char* argv[])
{
  std::string jsonPath;
  if (argc > 1)
  {
    jsonPath = argv[1];
  } else {
    throw std::runtime_error{"Error: you need to provide path to JSON file"};
  }

  std::ifstream file{jsonPath};
  if (!file) {
    throw std::runtime_error{"Error: unable to open file " + jsonPath};
  }
  json data;
  file >> data;
  //std::ostream& os;
  //processJSON(data, os);
}