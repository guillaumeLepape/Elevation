#ifndef OPTIONS_H
#define OPTIONS_H

#include <set>
#include <string_view>

namespace utils {

class Options {
 private:
  std::set<std::string_view> argv_;

 public:
  Options(int argc, char* argv[]);

  Options(const Options&) = delete;

  Options& operator=(const Options&) = delete;

  void print_help() const;

  bool noRule;
  bool help;
};
}  // namespace utils

#endif
