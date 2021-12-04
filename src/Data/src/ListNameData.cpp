/*!
 * \file ListNameData.cpp
 */

#include "ListNameData.h"

ListNameData::ListNameData(const std::string& folderFromRoot,
                           const std::string& nameFile)
    : Data(folderFromRoot, nameFile) {
  readData();
}

void ListNameData::readData() {
  std::for_each(std::cbegin(jsonObject_), std::cend(jsonObject_),
                [this](const auto& name) {
                  listName_.insert(static_cast<std::string>(name));
                });
}