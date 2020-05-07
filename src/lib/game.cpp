#include "game.h"

#include "word_loader.h"
#include "user_io.h"

using namespace std;

namespace WordBlasterTheGame {

  void Game::play(void) {
    // Load the words from a file this time
    WordLoader::load(&words, "./dictionaries/easy.txt");    // Calling static method !!!

    score = Score();    // Make sure that score is new
    for (unsigned int i = 0; i < 2; i++) {
      // Local variable required because we need the same word
      // at the end to check if it is correct
      std::string wordToType = words.get_random_word();

      UserIO::show_word_to_type(i, wordToType);
      std::string userWord = UserIO::request_user_to_type_word();

      // Check correctness and alter score if needed
      if (userWord == wordToType) {
        score.add_score_for_correct_word(wordToType);
      }
    }

    UserIO::show_final_score(score);
  }

};