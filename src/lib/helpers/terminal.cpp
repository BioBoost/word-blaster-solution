#include "terminal.h"
#include <cstdlib>
#include <conio.h>    // Windows only

namespace WordBlasterTheGame {

  // FIXME This does not work on linux
  Terminal::Key Terminal::pressed_key(void) {
    // Arrow key are two codes: 0 and keycode
    int key = getch();
    // std::cout << "Got key pressed: " << key << std::endl;
    if (key == 0) {
      key = getch();
      // std::cout << "Got Second key pressed: " << key << std::endl;
      switch (key) {
        case 72: return Key::UP;
        case 80: return Key::DOWN;
      }
    } else {
      switch (key) {
        case 13: return Key::ENTER;
      }
    }
    return Key::UNKNOWN;
  }
  
  void Terminal::clear(void) {
    // If this doesn't work on windows, you'll need: system("cls")
    system("clear");
  }

};
