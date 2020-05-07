#pragma once

#include "word_list.h"

namespace WordBlasterTheGame {

  /**
   * The Game class contains the basic
   * logic of the WordBlaster game.
   */
  class Game {

    public:
      /**
       * Play the game. This will requests words to be typed by
       * the user.
       *
       */
      void play(void);

    private:
      WordList words;

  };

};