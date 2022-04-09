#include <fmt/color.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <range/v3/algorithm/for_each.hpp>
#include <set>
#include <string>

nlohmann::json readJsonFile(const std::string& path) {
  // open json file
  std::ifstream jsonFile{path, std::ifstream::binary};

  // check if the file is opened
  assert(jsonFile.is_open());

  // declare json C++ object
  nlohmann::json jsonObject;

  // read jsonfile
  jsonFile >> jsonObject;

  jsonFile.close();

  return jsonObject;
}

auto read_list_of_name() {
  nlohmann::json jsonObject = readJsonFile("dataset/liste_des_prenoms.json");

  std::set<std::string> list_female_name;
  std::set<std::string> list_male_name;

  ranges::for_each(jsonObject, [&](const auto& person) {
    std::string name = person["fields"]["prenoms"];

    person["fields"]["sexe"] == "F" ? list_female_name.insert(name)
                                    : list_male_name.insert(name);
  });
  return std::pair{list_female_name, list_male_name};
}

void write_list_name(const std::set<std::string>& listName,
                     std::string&& nameFile) {
  nlohmann::json jsonObject(listName);

  std::ofstream jsonFile{fmt::format("dataset/{}.json", nameFile),
                         std::ofstream::binary};

  jsonFile << jsonObject;

  jsonFile.close();
}

auto main() -> int {
  auto [list_female_name, list_male_name] = read_list_of_name();

  write_list_name(list_female_name, "prenoms_feminins");
  write_list_name(list_male_name, "prenoms_masculins");

  return 0;
}
