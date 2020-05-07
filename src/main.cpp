#include <iostream>
#include "lib/word_list.h"
#include "lib/word_loader.h"

using namespace std;
using namespace WordBlasterTheGame;

int main() {
  cout << "Welcome to Word Blaster" << endl;
  cout << "Your next gen typing experience" << endl;

  // Test the WordList class
  WordList words;

  // Load the words from a file this time
  WordLoader::load(&words, "./dictionaries/easy.txt");    // Calling static method !!!

  cout << "Random word from list: " << words.get_random_word() << endl;

  return 0;
}