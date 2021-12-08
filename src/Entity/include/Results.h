#ifndef RESULTS_H
#define RESULTS_H

/*!
 * \file Results.h
 */

#include <fstream>

#include "Data.h"
#include "Player.h"

namespace data {
struct Results {
  Results() = default;
  Results(Player&&);

  Results(const Results&) = delete;
  Results(Results&&) = default;

  Results& operator=(const Results&) = delete;
  Results& operator=(Results&&) = default;

  virtual ~Results() = default;

  std::vector<Player> data;
};

Results read_results(std::string&& nameFolder, std::string&& nameFile);

void add(Results& results, Player&& player);

void write(const Results& results, std::string&& nameFolder,
           std::string&& nameFile);
}  // namespace data

#endif