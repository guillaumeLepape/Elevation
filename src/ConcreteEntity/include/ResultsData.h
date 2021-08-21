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
  std::list<Player*> results_;

 public:
  ResultsData();

  ~ResultsData() override;

  void readData() override;

  void addResult(Player* const player);
  void writeData() const;

  const std::list<Player*>& results() const { return results_; }
};

#endif