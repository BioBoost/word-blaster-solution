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

  // Let's try out some game logic

  for (unsigned int i = 0; i < 2; i++) {
    // Local variable required because we need the same word
    // at the end to check if it is correct
    std::string wordToType = words.get_random_word();

    cout << "Word #" << (i+1) << endl;
    cout << wordToType << endl << endl;

    cout << "Type your word here [enter to pass]: ";
    std::string userWord;
    getline(cin, userWord);

    if (userWord == wordToType) {
      cout << "Very good!" << endl << endl;
    } else {
      cout << "To bad :(" << endl << endl;
    }

  }

  return 0;
}