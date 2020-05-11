#include "menu.h"

namespace WordBlasterTheGame {

  void Menu::add(std::string item) {
    items.push_back({item});
    currentlySelected = 0;
  }

  std::vector<std::string> Menu::get_labels(void) {
    return items;
  }

  void Menu::select_next(void) {
    currentlySelected = ((currentlySelected+1) % items.size());
  }

  void Menu::select_previous(void) {
    currentlySelected--;
    if (currentlySelected < 0) {
      currentlySelected = items.size() - 1;
    }
  }

  std::string Menu::get_selected_label(void) {
    if (currentlySelected < 0) return "";

    return items[currentlySelected];
  }

};