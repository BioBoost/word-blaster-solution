#include "user_io.h"

#include <iostream>

using namespace std;

namespace WordBlasterTheGame {

  void UserIO::show_welcome(void) {
    cout << "Welcome to Word Blaster" << endl;
    cout << "Your next gen typing experience" << endl;
  }

  std::string UserIO::request_nickname(void) {
    cout << "Please enter a nickname to play with: ";
    std::string nickname;
    getline(cin, nickname);
    return nickname;
  }

  void UserIO::show_word_to_type(unsigned int number, std::string word) {
    cout << "Word #" << (number+1) << endl;
    cout << word << endl << endl;
  }

  std::string UserIO::request_user_to_type_word(void) {
    cout << "Type your word here [enter to pass]: ";
    std::string userWord;
    getline(cin, userWord);
    return userWord;
  }

  void UserIO::show_final_score(Score score) {
    cout << endl << "Your final score is " << score.total_score() << endl;
  }

};