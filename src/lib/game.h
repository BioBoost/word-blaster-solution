#pragma once

#include "word_list.h"
#include "score.h"
#include "scoreboard.h"
#include "player_manager.h"

namespace WordBlasterTheGame {

  /**
   * The Game class contains the basic
   * logic of the WordBlaster game.
   */
  class Game {

    public:
      /**
       * Create a game for the current player.
       *
       * @param player: a pointer to the player for
       * which the game is intended.
       * @param playerManager: a pointer to the
       * player manager object.
       */
      Game(Player * player, PlayerManager * playerManager);

    public:
      /**
       * Play the game. This will requests words to be typed by
       * the user.
       *
       */
      void play(void);

    private:
      WordList words;
      Player * player = nullptr;
      Scoreboard scoreboard;
      PlayerManager * playerManager = nullptr;
  };

};