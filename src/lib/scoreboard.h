#pragma once

#include <vector>
#include "score.h"

namespace WordBlasterTheGame {

  /**
   * Track the top scores of players.
   * Allows loading and saving scores.
   */
  class Scoreboard {

    public:

      /**
       * Add a score to the
       * scoreboard to be tracked.
       * 
       * @param score: score to be added to the board
       */
      void add(Score score);

    private:
      std::vector<Score> scores;

  };

};