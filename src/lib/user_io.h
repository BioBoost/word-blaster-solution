#pragma once

#include <string>
#include "score.h"

namespace WordBlasterTheGame {

  /**
   * Process all User IO to the terminal.
   */
  class UserIO {

    public:
      /**
       * Output a welcome message
       */
      static void show_welcome(void);

      /**
       * Output the next word for the user to type.
       *
       * @param word: word for the user to type
       */
      static void show_word_to_type(unsigned int number, std::string word);

      /**
       * Request a word to be typed by the user
       *
       * @returns the word that the user typed as a string
       */
      static std::string request_user_to_type_word(void);

      /**
       * Output the final score of the user.
       *
       * @param score: the final score to be shown
       */
      static void show_final_score(Score score);

  };

};