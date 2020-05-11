#include "user_io.h"

#include <iostream>

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
    Difficulty difficulty = Difficulty::NORMAL;

    Menu menu;
    menu.add("Easy");
    menu.add("Medium");
    menu.add("Hard");

    output_menu(&menu, "Please select a difficulty:");

    // FIX To be removed
    press_enter_to_continue();

    return difficulty;
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
      if (numbered) cout << (i+1) << ". ";
      cout << labels[i] << endl;
    }
  }

};