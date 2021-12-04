/*!
 * \file Options.cpp
 */

#include "Options.h"

#include <algorithm>
#include <iostream>

Options::Options(int argc, char* argv[])
    : argv_{[&argc, &argv]() {
        std::set<std::string_view> result;
        for (int i = 0; i < argc; ++i) {
          result.insert(argv[i]);
        }
        return result;
      }()},
      noRule_{
          std::binary_search(std::cbegin(argv_), std::cend(argv_), "-r") or
          std::binary_search(std::cbegin(argv_), std::cend(argv_), "--rule")},
      help_{
          std::binary_search(std::cbegin(argv_), std::cend(argv_), "-h") or
          std::binary_search(std::cbegin(argv_), std::cend(argv_), "--help")} {}

void Options::print_help() const {
  std::cout << "Allowed options :\n";
  std::cout << "-h, --help : print help message\n";
  std::cout << "-r, --rule : If this option is selected, the rules and "
               "tutorials are not printed\n";
}