#include "Options.h"

#include <fmt/core.h>

#include <algorithm>
#include <iostream>

namespace utils {
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
  fmt::print("Allowed options :\n");
  fmt::print("-h, --help : print help message\n");
  fmt::print(
      "-r, --rule : If this option is selected, the rules and "
      "tutorials are not printed\n");
}
}  // namespace utils