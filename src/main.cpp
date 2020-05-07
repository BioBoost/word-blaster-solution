#include <iostream>
#include "lib/game.h"

using namespace std;
using namespace WordBlasterTheGame;

int main() {
  cout << "Welcome to Word Blaster" << endl;
  cout << "Your next gen typing experience" << endl;

  // Let's play a game of word blaster
  Game wordblaster;
  wordblaster.play();

  return 0;
}