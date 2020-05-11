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

    public:
      /**
       * Select the next item in the menu list. If the
       * currently selected item was the last
       * in the list, the selector will jump to the top
       * of the menu.
       */
      void select_next(void);

      /**
       * Select the previous item in the menu list. If the
       * currently selected item was the first
       * in the list, the selector will jump to the bottom
       * of the menu.
       */
      void select_previous(void);

      /**
       * Returns the label of the currently selected item.
       */
      std::string get_selected_label(void);

    private:
      std::vector<std::string> items;
      int currentlySelected = -1;
  };

};