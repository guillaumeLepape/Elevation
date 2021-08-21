/*!
 * \file Options.cpp
 */

#include "Options.h"

#include <algorithm>
#include <iostream>
#include <set>

Options::Options(int argc, char* argv[]) : noRule_(false), help_(false) {
  initializeAttribute(argc, argv);
}

void Options::initializeAttribute(int argc, char* argv[]) {
  std::set<std::string_view> argv_set;

  for (int i = 0; i < argc; i++) {
    argv_set.insert(argv[i]);
  }

  noRule_ =
      std::binary_search(std::cbegin(argv_set), std::cend(argv_set), "-r") or
      std::binary_search(std::cbegin(argv_set), std::cend(argv_set), "--rule");

  help_ =
      std::binary_search(std::cbegin(argv_set), std::cend(argv_set), "-h") or
      std::binary_search(std::cbegin(argv_set), std::cend(argv_set), "--help");
}

void Options::print_help() const {
  std::cout << "Allowed options :\n";
  std::cout << "-h, --help : print help message\n";
  std::cout << "-r, --rule : If this option is selected, the rules and "
               "tutorials are not printed\n";
}