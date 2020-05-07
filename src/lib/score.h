#pragma once

#include <string>

namespace WordBlasterTheGame {

  class Score {

    public:
      /**
       * Add score for a word that was typed correctly.
       * In its current state the length of word will be
       * taken into account for determining the score.
       *
       * @param word: word that the user typed correctly
       */
      void add_score_for_correct_word(std::string word);
      
    public:
      /**
       * Get the total score.
       *
       * @returns the total score as an unsigned integer
       */
      unsigned int total_score(void);

    private:
      unsigned int score = 0;
  };

};