/*!
 * \file TutorialWriter.cpp
 */

#include "TutorialWriter.h"

#include <cpp-terminal/terminal.h>

#include <iostream>

#include "Pause.h"

TutorialWriter::TutorialWriter(
    const std::string& title, const std::vector<std::string>& tutorialStatement)
    : title_(title), tutorialStatement_(tutorialStatement) {}

void TutorialWriter::writeTutorial() const {
  Pause::pause();

  std::cout << "\n " << Term::color(Term::bg::magenta)
            << Term::color(Term::style::bold) << title_
            << Term::color(Term::bg::reset) << Term::color(Term::style::reset);

  std::cout << "\n"
            << Term::color(Term::fg::black) << Term::color(Term::style::bold)
            << "========" << Term::color(Term::fg::reset)
            << Term::color(Term::style::reset);

  for (long unsigned int i = 0; i < tutorialStatement_.size(); i++) {
    Pause::pause();

    std::cout << "\n " << Term::color(Term::fg::magenta)
              << Term::color(Term::style::bold) << tutorialStatement_[i]
              << Term::color(Term::fg::reset)
              << Term::color(Term::style::reset);
  }

  std::cout << "\n";
}