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

  std::vector<Score> Scoreboard::get_scores(void) {
    // This will return a copy of the internal std::vector.
    // Not most performant solution but on the other side this way
    // external code cannot change the scores.
    return scores;
  }

  void Scoreboard::load(std::string filename) {
    // File stream object
    std::ifstream file;
    file.open(filename);

    if (!file) {
      // Let's do nothing here as there are no scores yet.
      // File will be created on save
      return;
    }

    // Read the scores from the file
    do {
      std::string name;
      std::string points;
      
      // The separator can be supplied to getline
      std::getline(file, name, ',');
      std::getline(file, points);

      if (name != "" && points != "") {
        int score = std::stoi(points);
        add(Score(get_player_by_nickname(name), score));
      }
    } while (file.good());

    // Close the file
    file.close();
  }

  Player * Scoreboard::get_player_by_nickname(std::string nickname) {
    Player * player = nullptr;
    for (auto && score : scores) {
      if (score.get_player()->get_nickname() == nickname) {
        player = score.get_player();
        break;
      }
    }

    if (!player) {
      player = new Player(nickname);
    }

    return player;
  }

};