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
       * Output the welcome screen
       */
      static void show_welcome_screen(void);

      /**
       * Request a nickname from the user
       *
       * @returns the nickname of the user as a string
       */
      static std::string request_nickname(void);

      /**
       * Output the next word for the user to type
       * and let the user input an attempt to copy
       * the word.
       *
       * @param number: the index number of the word
       * @param word: word for the user to type
       */
      static std::string request_user_attempt_at_word(unsigned int number, std::string word);

      /**
       * Output the final score of the user.
       *
       * @param score: the final score to be shown
       */
      static void show_final_score(Score score);

    private:
      /**
       * Show the heading of the game that includes
       * the title of the app.
       */
      static void show_heading(void);

      /**
       * Request the user to press the ENTER key before
       * continuing to the next screen.
       */
      static void press_enter_to_continue(void);

      /**
       * Clear the terminal screen.
       */
      static void clear_terminal(void);

      /**
       * Read a string from the terminal.
       */
      static std::string request_string_input(void);

  };

};