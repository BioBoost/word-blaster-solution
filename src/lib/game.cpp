#include "game.h"

#include "word_loader.h"
#include "user_io.h"

namespace WordBlasterTheGame {

  const std::string Game::DICTIONARY_FILES[] = {
    "./dictionaries/easy.txt",
    "./dictionaries/normal.txt",
    "./dictionaries/hard.txt"
  };

  const std::string Game::SCOREBOARD_FILES[] = {
    "./easy_scores.txt",
    "./normal_scores.txt",
    "./hard_scores.txt"
  };

  Game::Game(Player * player, PlayerManager * playerManager)
    : scoreboard(playerManager) {
       // Use constructor initialization list since
       // no default constructor exists for Scoreboard
    this->player = player;
    this->playerManager = playerManager;
    change_difficulty(Difficulty::NORMAL);
  }

  void Game::play(void) {
    Score score(player);   // Create new score object for this play
    for (unsigned int i = 0; i < 2; i++) {
      // Local variable required because we need the same word
      // at the end to check if it is correct
      std::string wordToType = words.get_random_word();

      std::string userWord = UserIO::request_user_attempt_at_word(i, wordToType);

      // Check correctness and alter score if needed
      if (userWord == wordToType) {
        score.add_score_for_correct_word(wordToType);
      }
    }

    scoreboard.add(score);
    save_scoreboard();
    UserIO::show_final_score(score);
    UserIO::show_scoreboard(&scoreboard);
  }

  void Game::change_difficulty(Difficulty difficulty) {
    this->difficulty = difficulty;
    load_dictionary();
    load_scoreboard();
  }

  void Game::load_dictionary(void) {
    words.clear();
    WordLoader::load(&words, DICTIONARY_FILES[(int)(difficulty)]);    // Calling static method !!!
  }

  void Game::load_scoreboard(void) {
    scoreboard.load(SCOREBOARD_FILES[(int)(difficulty)]);
  }

  void Game::save_scoreboard(void) {
    scoreboard.save(SCOREBOARD_FILES[(int)(difficulty)]);
  }

};