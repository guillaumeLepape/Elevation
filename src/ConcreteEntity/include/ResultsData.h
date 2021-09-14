#ifndef RESULTS_DATA_H
#define RESULTS_DATA_H

/*!
 * \file ResultsData.h
 */

#include <fstream>
#include <list>

#include "Data.h"
#include "Player.h"

class ResultsData : public Data {
 private:
  std::vector<Player> results_;

 public:
  ResultsData();

  ResultsData(const ResultsData&) = delete;
  ResultsData(ResultsData&&) = default;

  ResultsData& operator=(const ResultsData&) = delete;
  ResultsData& operator=(ResultsData&&) = default;

  virtual ~ResultsData() = default;

  void readData() override;

  void addResult(Player* const player);
  void writeData() const;

  const std::vector<Player>& results() const { return results_; }
};

#endif