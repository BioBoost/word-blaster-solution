#include "menu.h"

namespace WordBlasterTheGame {

  void Menu::add(std::string item) {
    items.push_back({item});
  }

  std::vector<std::string> Menu::get_labels(void) {
    return items;
  }

};