#pragma once

#include "word_list.h"
#include "score.h"

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
       * @param player: the player for which the game
       * is intended
       */
      Game(Player player);

    public:
      /**
       * Play the game. This will requests words to be typed by
       * the user.
       *
       */
      void play(void);

    private:
      WordList words;
      Player player;

  };

};