#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <set>
#include <string>

nlohmann::json readJsonFile(const std::string& path) {
  // open json file
  std::ifstream jsonFile(path, std::ifstream::binary);

  // check if the file is opened
  assert(jsonFile.is_open());

  // declare json C++ object
  nlohmann::json jsonObject;

  // read jsonfile
  jsonFile >> jsonObject;

  jsonFile.close();

  return jsonObject;
}

void readListeDesPrenoms(std::set<std::string>& listFemaleName,
                         std::set<std::string>& listMasculineName) {
  nlohmann::json jsonObject = readJsonFile("../dataset/liste_des_prenoms.json");

  for (auto i = jsonObject.cbegin(); i != jsonObject.cend(); i++) {
    std::string name = (std::string)(*i)["fields"]["prenoms"];

    if (((std::string)(*i)["fields"]["sexe"]) == "F") {
      listFemaleName.insert(name);
    } else {
      listMasculineName.insert(name);
    }
  }
}

void writeListName(const std::set<std::string>& listName,
                   const std::string& nameFile) {
  nlohmann::json jsonObject(listName);

  std::ofstream jsonFile("../dataset/" + nameFile + ".json",
                         std::ofstream::binary);

  jsonFile << jsonObject;

  jsonFile.close();
}

int main() {
  std::set<std::string> listFeminineName;
  std::set<std::string> listMasculineName;

  readListeDesPrenoms(listFeminineName, listMasculineName);

  writeListName(listFeminineName, "prenoms_feminins");
  writeListName(listMasculineName, "prenoms_masculins");

  return 0;
}
