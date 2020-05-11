#include "user_io.h"

#include <iostream>
#include "helpers/terminal.h"

using namespace std;

namespace WordBlasterTheGame {

  void UserIO::show_welcome_screen(void) {
    clear_terminal();
    show_heading();
    cout << "Welcome to Word Blaster" << endl;
    cout << "Your next gen typing experience" << endl << endl;
    press_enter_to_continue();
  }

  std::string UserIO::request_nickname(void) {
    clear_terminal();
    show_heading();
    cout << "Please enter a nickname to play with: ";
    return request_string_input();
  }

  Difficulty UserIO::request_difficulty(void) {
    Menu menu;
    menu.add("Easy", Screen::MAIN_MENU);
    menu.add("Medium", Screen::MAIN_MENU);
    menu.add("Hard", Screen::MAIN_MENU);

    Terminal::Key key;
    do {
      clear_terminal();
      show_heading();
      output_menu(&menu, "Please select a difficulty:");
      cout << endl << "Use the arrow keys to select a menu item and ENTER to select it." << endl;
      key = Terminal::pressed_key();
      if (key == Terminal::Key::DOWN) {
        menu.select_next();
      } else if (key == Terminal::UP) {
        menu.select_previous();
      }
    } while (key != Terminal::Key::ENTER);

    if (menu.get_selected_item().get_label() == "Easy") return Difficulty::EASY;
    else if (menu.get_selected_item().get_label() == "Hard") return Difficulty::HARD;
    else return Difficulty::NORMAL;
  }

  Screen UserIO::show_main_menu(void) {
    Menu mainMenu;
    mainMenu.add("Play New Game", Screen::PLAY);
    mainMenu.add("Change Difficulty", Screen::DIFFICULTY);
    mainMenu.add("Show Scoreboard", Screen::SCOREBOARD);
    mainMenu.add("Exit", Screen::EXIT);

    Terminal::Key key;
    do {
      clear_terminal();
      show_heading();
      output_menu(&mainMenu, "");
      cout << endl << "Use the arrow keys to select a menu item and ENTER to select it." << endl;
      key = Terminal::pressed_key();
      if (key == Terminal::Key::DOWN) {
        mainMenu.select_next();
      } else if (key == Terminal::UP) {
        mainMenu.select_previous();
      }
    } while (key != Terminal::Key::ENTER);

    return mainMenu.get_selected_item().get_next_screen();
  }

  std::string UserIO::request_user_attempt_at_word(unsigned int number, std::string word) {
    clear_terminal();
    show_heading();
    cout << endl << "Word #" << (number+1) << endl;
    cout << word << endl << endl;

    cout << "Type your word here [enter to pass]: ";
    return request_string_input();;
  }

  void UserIO::show_final_score(Score score) {
    clear_terminal();
    show_heading();
    cout << endl << "Your final score is " << score.total_score() << endl << endl;
    press_enter_to_continue();
  }

  void UserIO::show_scoreboard(Scoreboard * board) {
    clear_terminal();
    show_heading();
    cout << endl << "HIGHSCORES:" << endl;
    cout << "-----------" << endl;

    for (auto && score : board->get_scores()) {
      cout << to_string(score.total_score()) << " ["
            << score.get_player()->get_nickname() << "]" << endl;
    }
    cout << endl;
    press_enter_to_continue();
  }

  void UserIO::show_heading(void) {
    string separator = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    cout << separator << endl;
    cout << "~ Word Blaster - Next Gen Typing Motivator        ~" << endl;
    cout << separator << endl << endl;
  }

  void UserIO::press_enter_to_continue(void) {
    cout << "PRESS ENTER TO CONTINUE" << endl;
    request_string_input();
  }
  
  void UserIO::clear_terminal(void) {
    // If this doesn't work on windows, you'll need: system("cls")
    system("clear");
  }

  std::string UserIO::request_string_input(void) {
    std::string input;
    getline(cin, input);
    return input;
  }

  void UserIO::output_menu(Menu * menu, std::string title, bool numbered) {
    std::vector<std::string> labels = menu->get_labels();
    cout << title << endl;
    for (unsigned int i = 0; i < labels.size(); i++) {
      if (menu->get_selected_item().get_label() == labels[i]) {
        cout << "==> ";
      } else {
        cout << "    ";
      }

      if (numbered) cout << (i+1) << ". ";
      cout << labels[i] << endl;
    }
  }

};