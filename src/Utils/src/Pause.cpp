/*!
 * \file Pause.cpp
 */

#include "Pause.h"

namespace Pause {
void pause() {
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
}  // namespace Pause