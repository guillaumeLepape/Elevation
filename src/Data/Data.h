#ifndef DATA_H
#define DATA_H

/*!
 * \file Data.h
 */

#include <nlohmann/json.hpp>

/*! \class Data
 * \brief Abstract class for data
 *
 * Abstract class containing the json data for various type of data (herited
 * class) and reader of json file
 *
 */

class Data {
 private:
  void openFile(const std::string& folderFromRoot, const std::string& fileName);

 protected:
  nlohmann::json jsonObject_;

  virtual void readData() = 0;

 public:
  Data(const std::string& folderFromRoot, const std::string& fileName);

  Data(const Data& data) = delete;

  virtual ~Data() = default;
};

#endif