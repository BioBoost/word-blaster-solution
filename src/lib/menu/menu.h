#pragma once

#include <vector>
#include <string>

namespace WordBlasterTheGame {

  class Menu {

    public:
      /**
       * Add an item to the menu
       * 
       * @param item: the label for the item to
       * be shown to the user.
       */
      void add(std::string item);

      /**
       * Get an std::vector containing all the labels
       * as std::string's for the menu.
       * 
       * @return an std::vector<std::string> that contains
       * the labels for the menu items
       */
      std::vector<std::string> get_labels(void);

    private:
      std::vector<std::string> items;
  };

};