#include "game.h"

#include "word_loader.h"
#include "lib/user_io.h"

using namespace std;

namespace WordBlasterTheGame {

  void Game::play(void) {
    // Load the words from a file this time
    WordLoader::load(&words, "./dictionaries/easy.txt");    // Calling static method !!!

    for (unsigned int i = 0; i < 2; i++) {
      // Local variable required because we need the same word
      // at the end to check if it is correct
      std::string wordToType = words.get_random_word();

      UserIO::show_word_to_type(i, wordToType);
      std::string userWord = UserIO::request_user_to_type_word();

      // We'll refactor this in the next step
      // if (userWord == wordToType) {
      //   cout << "Very good!" << endl << endl;
      // } else {
      //   cout << "To bad :(" << endl << endl;
      // }

    }
  }

};