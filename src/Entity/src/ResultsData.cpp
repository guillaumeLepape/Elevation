/*!
 * \file ResultsData.cpp
 */

#include "ResultsData.h"

#include <iomanip>

ResultsData::ResultsData() : Data("results", "results") { readData(); }

ResultsData::ResultsData(Player&& player) : Data("results", "results") {
  results_.push_back(std::move(player));
  readData();
}

void ResultsData::readData() {
  std::transform(std::cbegin(jsonObject_), std::cend(jsonObject_),
                 std::back_inserter(results_),
                 [](const auto& result) { return Player{result}; });
}

void ResultsData::addResult(Player&& player) {
  if (std::find_if(std::cbegin(results_), std::cend(results_),
                   [&player](const auto& p) {
                     return p.id() == player.id();
                   }) == std::cend(results_)) {
    results_.push_back(std::move(player));
  }
}

void ResultsData::writeData() const {
  std::string path = "results/results.json";

  // open json file
  std::ofstream jsonFile(path);

  // check if the file is opened
  assert(jsonFile.is_open());

  nlohmann::json jsonObjectOutput;

  std::for_each(std::cbegin(results_), std::cend(results_),
                [&jsonObjectOutput](const auto& res) {
                  nlohmann::json jsonPlayer = res.write();
                  jsonObjectOutput.push_back(jsonPlayer);
                });

  // read jsonfile
  jsonFile << std::setw(4) << jsonObjectOutput;

  jsonFile.close();
}