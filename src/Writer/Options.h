#ifndef OPTIONS_H
#define OPTIONS_H

/*!
 * \file Options.h
 */

class Options {
 private:
  void initializeAttribute(int argc, char* argv[]);

 public:
  Options(int argc, char* argv[]);

  void print_help() const;

  bool noRule_;
  bool help_;
};

#endif