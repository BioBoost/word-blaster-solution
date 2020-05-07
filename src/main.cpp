#include <iostream>
#include "lib/word_list.h"

using namespace std;
using namespace WordBlasterTheGame;

int main() {
  cout << "Welcome to Word Blaster" << endl;
  cout << "Your next gen typing experience" << endl;

  // Test the WordList class
  WordList words;
  words.add("hello");
  words.add("world");
  words.add("dude");

  cout << "Random word from list: " << words.get_random_word() << endl;

  return 0;
}