#include "word_blaster.h"
#include "user_io.h"
#include "menu/menu.h"

namespace WordBlasterTheGame {

  void WordBlaster::start(void) {
    UserIO::show_welcome_screen();
    currentPlayer = playerManager.get_player_by_nickname(UserIO::request_nickname());
    game = new Game(currentPlayer, &playerManager);
    show_main_menu();
  }

  void WordBlaster::show_main_menu(void) {
    Screen next;
    do {
      next = UserIO::show_main_menu();

      switch (next) {
        case Screen::DIFFICULTY:
          game->change_difficulty(UserIO::request_difficulty());
          break;

        case Screen::PLAY:
          game->play();
          break;

        case Screen::SCOREBOARD:
          UserIO::show_scoreboard(game->get_scoreboard());
          break;

        default: break;
      }
    } while (next != Screen::EXIT);
  }

  WordBlaster::~WordBlaster(void) {
    delete currentPlayer;
    delete game;
  }

};