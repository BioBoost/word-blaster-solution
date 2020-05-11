#include <iostream>
#include "lib/game.h"
#include "lib/user_io.h"
#include "lib/player.h"
#include "lib/player_manager.h"
#include "lib/menu/menu.h"

using namespace std;
using namespace WordBlasterTheGame;

int main() {
  UserIO::show_welcome_screen();

  // Create PlayerManager for all the games
  PlayerManager playerManager;

  // Ask player for nickname and request player manager for player object
  Player * currentPlayer = playerManager.get_player_by_nickname(UserIO::request_nickname());

  // Let's play a game of word blaster
  Game wordblaster(currentPlayer, &playerManager);
  wordblaster.change_difficulty(UserIO::request_difficulty());
  wordblaster.play();

  return 0;
}