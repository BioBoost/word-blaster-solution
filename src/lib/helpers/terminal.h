#pragma once

namespace WordBlasterTheGame {

  class Terminal {

    public: enum Key {
      UP,
      DOWN,
      ENTER,
      UNKNOWN
    };

    public:

      /**
       * Wait for the user to press a single key
       * and return the pressed key.
       * 
       * @returns the pressed Key or Key::UNKNOWN
       * if the pressed key is not supported.
       */
      static Key pressed_key(void);

  };

};
