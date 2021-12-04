#ifndef OPTIONS_H
#define OPTIONS_H

/*!
 * \file Options.h
 */

#include <set>

class Options {
 private:
  std::set<std::string_view> argv_;

 public:
  Options(int argc, char* argv[]);

  Options() = delete;

  Options(const Options&) = delete;
  Options(Options&&) = default;

  Options& operator=(const Options&) = delete;
  Options& operator=(Options&&) = default;

  ~Options() = default;

  void print_help() const;

  bool noRule_;
  bool help_;
};

#endif