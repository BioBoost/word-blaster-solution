#include "scoreboard.h"

#include <iostream>
#include <fstream>

namespace WordBlasterTheGame {

  void Scoreboard::add(Score score) {
    scores.push_back(score);
  }

  void Scoreboard::save(std::string filename) {
    std::ofstream output;
    output.open(filename);    // Default mode is ios::out

    if (!output) {
      std::cerr << "Could not save the scores to the file " << filename << std::endl;
      return;
    }

    // Write the scores to the file
    for (auto && score : scores) {
      output << score.get_player()->get_nickname() << ","
        << score.total_score() << std::endl;
    }

    // Close the file
    output.close();
  }

};