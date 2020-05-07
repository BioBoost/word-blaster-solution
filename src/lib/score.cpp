#include "score.h"

namespace WordBlasterTheGame {

  Score::Score(Player * player) {
    this->player = player;
  }

  void Score::add_score_for_correct_word(std::string word) {
    score += word.length();
  }

  unsigned int Score::total_score(void) {
    return score;
  }

};