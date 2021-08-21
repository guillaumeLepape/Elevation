#ifndef NAME_DATA_H
#define NAME_DATA_H

/*!
 * \file ListNameData.h
 */

#include <set>

#include "Data.h"

class ListNameData : public Data {
 private:
  std::set<std::string> listName_;

 public:
  ListNameData(const std::string& folderFromRoot, const std::string& nameFile);

  void readData() override;

  const std::set<std::string>& listName() const { return listName_; }

  ~ListNameData() override = default;
};

#endif