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

      /**
       * Save the scores to a file.
       * 
       * @param filename: path to the file where the
       * scores need to be saved.
       */
      void save(std::string filename);

      /**
       * Get the list of scores as an std::vector.
       * 
       * @returns an std::vector of Score objects
       */
      std::vector<Score> get_scores(void);

      /**
       * Load the scores from a file.
       * 
       * @param filename: path to the file where the
       * scores are stored.
       */
      void load(std::string filename);

    private:
      /**
       * Get a player from the scoreboard by
       * his/her nickname. If the player
       * does not exist yet, a new player
       * is returned.
       * 
       * @param nickname: the nickname of the player
       * 
       * @returns a pointer to an existing or new player object
       */
      Player * get_player_by_nickname(std::string nickname);

    private:
      std::vector<Score> scores;

  };

};