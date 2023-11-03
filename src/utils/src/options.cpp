#include "elevation/utils/options.h"

#include <fmt/core.h>

#include <algorithm>
#include <iostream>
#include <range/v3/algorithm/binary_search.hpp>

namespace utils {
Options::Options(int argc, char* argv[])
    : argv_{[&argc, &argv]() {
        std::set<std::string_view> result;
        for (int i = 0; i < argc; ++i) {
          result.insert(argv[i]);
        }
        return result;
      }()},
      noRule_{ranges::binary_search(argv_, "-r") or
              ranges::binary_search(argv_, "--rule")},
      help_{ranges::binary_search(argv_, "-h") or
            ranges::binary_search(argv_, "--help")} {}

void Options::print_help() const {
  fmt::print("Allowed options :\n");
  fmt::print("-h, --help : print help message\n");
  fmt::print(
      "-r, --rule : If this option is selected, the rules and "
      "tutorials are not printed\n");
}
}  // namespace utils
