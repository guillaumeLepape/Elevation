#ifndef PAUSE_H
#define PAUSE_H

/*!
 * \file Pause.h
 */

#include <cpp-terminal/terminal.h>

/*!
 * \class Pause
 * \brief class with only one static function to pause message
 */

class Pause {
 public:
  /*!
   * \brief Pause
   * pause message and waiting for enter entry
   */
  static void pause() {
    try {
      Term::Terminal term;

      bool on = true;
      while (on) {
        int key = term.read_key();

        if (key == Term::Key::ENTER) {
          on = false;
        }
      }
    } catch (const std::runtime_error& re) {
      std::cerr << "Runtime error: " << re.what() << std::endl;
    } catch (...) {
      std::cerr << "Unknown error." << std::endl;
    }
  }
};

#endif