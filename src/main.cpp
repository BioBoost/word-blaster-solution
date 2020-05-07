#include <iostream>
#include "lib/game.h"
#include "lib/user_io.h"
#include "lib/player.h"

using namespace std;
using namespace WordBlasterTheGame;

int main() {
  UserIO::show_welcome_screen();

  // Ask user for nickname and create player with that nickname
  Player player(UserIO::request_nickname());

  // Let's play a game of word blaster
  Game wordblaster(player);
  wordblaster.play();

  return 0;
}