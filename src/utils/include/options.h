#ifndef OPTIONS_H
#define OPTIONS_H

#include <set>
#include <string_view>

namespace utils {

class Options {
 private:
  std::set<std::string_view> argv_;
  bool noRule_;
  bool help_;

 public:
  Options(int argc, char* argv[]);

  Options(const Options&) = delete;
  Options(Options&&) noexcept = default;

  Options& operator=(const Options&) = delete;
  Options& operator=(Options&&) noexcept = default;

  ~Options() noexcept = default;

  void print_help() const;

  [[nodiscard]] bool noRule() const { return noRule_; }
  [[nodiscard]] bool help() const { return help_; }
};
}  // namespace utils

#endif
