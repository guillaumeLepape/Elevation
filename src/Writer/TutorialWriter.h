#ifndef TUTORIAL_WRITER_H
#define TUTORIAL_WRITER_H

/*!
 * \file TutorialWriter.h
 */

#include <string>
#include <vector>

class TutorialWriter {
 private:
  std::string title_;
  std::vector<std::string> tutorialStatement_;

 public:
  TutorialWriter(const std::string& title,
                 const std::vector<std::string>& tutorialStatement);

  void writeTutorial() const;
};

#endif