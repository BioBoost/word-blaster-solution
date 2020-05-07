#include <iostream>
#include "lib/game.h"
#include "lib/user_io.h"

using namespace std;
using namespace WordBlasterTheGame;

int main() {

  UserIO::show_welcome();

  // Let's play a game of word blaster
  Game wordblaster;
  wordblaster.play();

  return 0;
}