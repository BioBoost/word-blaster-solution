#pragma once

#include <string>
#include "score.h"
#include "scoreboard.h"
#include "menu/menu.h"
#include "difficulty.h"

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
       * Show the menu to the user and request
       * the user to select an item from the menu.
       * 
       * @param menu: the menu to display to the user
       * 
       * @returns the selected MenuItem from the menu
       */
      static MenuItem request_menu_selection(Menu * menu);

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

      /**
       * Output scoreboard screen with all the
       * player scores.
       *
       * @param board: pointer to Scoreboard object
       * that contains the player scores.
       */
      static void show_scoreboard(Scoreboard * board);

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
       * Read a string from the terminal.
       */
      static std::string request_string_input(void);

      public:
      /**
       * Output a menu to the terminal with the given title.
       * 
       * @param menu: the menu that needs to be shown in
       * the terminal
       * @param numbered: indicate if each label should be prefixed
       * with a number from 1 to the size of the vector
       */
      static void output_menu(Menu * menu, bool numbered=true);

  };

};