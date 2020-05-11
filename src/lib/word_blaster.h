#pragma once

#include "game.h"
#include "player.h"
#include "player_manager.h"

namespace WordBlasterTheGame {

  /**
   * The WordBlaster class controls the overal
   * application flow. Main menu, track the current game,
   * track the player(s), ...
   */
  class WordBlaster {

    public:
      /**
       * Starts the whole WordBlaster application.
       * 
       * Starts by requesting the player's nickname
       * and then shows the game's main menu.
       */
      void start(void);

    public:
      /**
       * WordBlaster destructor. Destroys the game
       * and player that were created dynamically.
       * 
       * Should not be called directly.
       */
      ~WordBlaster(void);

    private:
      /**
       * Show the main menu of the game and let
       * the player navigate through the different
       * options.
       */
      void show_main_menu(void);

    private:
      PlayerManager playerManager;
      Player * currentPlayer = nullptr;
      Game * game = nullptr;
  };

};