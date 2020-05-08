# Word Blaster

A C++ typing game.

Word Blaster challenges the player to type a list of words as fast as possible and without mistakes. It tracks the scores of the player using a scoreboard and also allows the user to select the appropriate difficulty.

The words are selected randomly from text files located on the file system.

## Building and running the game

This project is equipped with a make file to build and run the game. Just run the command bellow.

```cpp
make run
```

### Doxygen

This project contains doxygen comments which can be generated into a fancy API site. Just install [doxygen](http://www.doxygen.nl/) and run the `doxygen` or `make docs` command (you may need to add doxygen to your PATH) in the root directory of this project. The html output can be found at [./docs/html/index.html](./docs/html/index.html).

## Part of C++ Course

This project was a challenge for the students of the VIVES University College in Bruges as part of the C++ course.

## Original Assignment

Build a word typing game that challenges the user to type over words as fast as possible.

Let the user login using a nickname. Also allow selection of difficulty.

Select random words from a file. Can be plain text file. Make sure that the difficulty influences the word selection from the file.

The score should be calculated based on the correctness of the user's typing and also the speed with which the user finishes each challenge. Calculate a score based on at least these parameters.

Allow the score to be saved to a file and displayed in a scoreboard.

Try to make the game a bit more appealing by using for example ascii art or other techniques for visualization inside the console.

Document the project with a decent `README.md` and UML class diagrams. Also explain new techniques or things you used to build the app.

Also include a `Makefile` so the project can be easily built using a single `make` command.

## Steps Taken

Step titles are same as the commit messages. This way you can follow along.

### Step 1 - Simple Hello World

Output basic message and make sure everything (compiler and makefile) works.

### Step 2 - A WordList class

WordList can track a list of words and provide randomly selected word.

Single responsibility so no loading from file and such. Responsibility of another class.

### Step 3 - A WordLoader class

Words need to be loaded from a file. `WordLoader` loads words from a file and places them in a `WordList`.

Later on different files will exist for the different difficulties. However, `WordLoader` does not have to know this.

`WordLoader` does not need to keep any state for its single method. Because of this the method is made `static` which means it is not called on an object of `WordLoader` but rather on the class itself.

### Step 4 - Some Game Logic

Basic game logic consists of asking the user to repeat a certain number of words. This can be accomplished by a simple `for` construct. In this step the code is placed in main. Next steps will refactor this.

### Step 5 - A Game class

This kind of logic cannot be kept in main. This typically screams for a `Game` class with a basic `play()` method. `WordList` will also need to be moved as attribute of `Game` (composition).

Tip: Just move the `for` loop into the `play()` method and check out what extra information you need for the code to work.

This still requires some serious refactoring.

### Step 6 - User Input Output class

Problem with the current `Game` class is the fact that it handles user IO. If possible, it is a good idea to separate the user IO from the game logic. This would actually allow the game to be used with a GUI instead of a terminal and only a single class would have to be provided.

If this separation is done early in the development process, it's a much less painful operation.

Basically we need a class that has some methods that can request a word from the user, output the next word, output some stats about his/her score and so on. This class will not need to track any state as each method call will require all the needed information to be supplied. The `Game` class tracks all state here.

The end result should be a `Game` class without a single `cout`, `getline` or `cin`. The `UserIO` methods should not contain any game logic. This means that for example the comparison of the generated word and the user input should happen in the game class.

### Step 7 - A Score class

At the moment no score is tracked for the player. One could state that we could just track the number of wrongly typed words in the Game class but if the scoring mechanism will get a bit more complex, it will needs it's own class.

For the moment we can use the length of the word as a score parameter. Later we can add timing and such.

In one of the following steps we will also be adding a `Player` to the game to which an object of `Score` will belong.

Game will need to track the `Score` of the current game. An attribute can be added to the class for this.

Let's also add a method to `UserIO` to output the final score of the user.

### Step 8 - A Player class

It's time to add a player. This will be required once we want to start keeping a score board.

When the application starts we will ask the user for a nickname and store this inside of the `Player` class. The player should then be injected into the `Game` object upon construction. This will later allow us to ask the player if he/she wishes to start another game without requiring hem/her to enter the nickname again.

We will also alter the `Score` class so it keep a pointer to the `Player` to which the score belongs. This can also be accomplished via the constructor.

Why not add a Score object as an attribute to Player? Well basically because a Player will be able to have multiple score's in the `Scoreboard`. That would mean we would have to track these in a list (inside of player). On top of that the Player object doesn't really need to know all of its scores. The Scoreboard will need to track these.

The Score object of `Game` should also be moved in the `play` method as a local variable (instead of an attribute) for a couple of reasons:

* we only need it in the play method
* every time play is called a new score is required
* the constructor of game takes in a Player object, we cannot use a pointer to this object to initialize score as it is a copy which will go out of scope after the constructor is done.

If we were to follow this route (as an attribute of game) we would need to create the score on the heap.

### Step 9 - Refactor IO a bit

While we have some functionality already, the output looks really bad. Time to refactor the terminal output a bit.

Maybe we should build some sort of screens with similar layout.

For example:

```text
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~ Word Blaster - Next Gen Typing Motivator        ~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Welcome to Word Blaster
Your next gen typing experience

PRESS ENTER TO CONTINUE
```

By adding some private methods such as `show_heading()` to `UserIO`, each output screen can be made similar in layout.

### Step 10 - A ScoreBoard class

Typically a game tracks the scores of the players between different game sessions by saving the scores in a file. These will then be loaded when the user starts the game.

We will start of with a `Scoreboard` class that can track a list of scores. Using an `std::vector` this will be easiest. 

An object of `Scoreboard` can then be added to the game. Then the score of the player can be added to the board once the game is finished.

### Step 11 - Saving the Scoreboard

To save the scores we will be making use of a simple separator between the score and the player name. CSV (Comma Separated Values) is a popular format where each property is separated with a comma and each entry is saved as a single line. This parses more easily after the file has been loaded too.

To be able to save the player name along with the score we will also need a `get_player()` method for `Score`.

### Step 12 - Displaying the Scoreboard

To display the scoreboard we will need to add a method to the `UserIO` class. However to be able to access the actual score objects a method `get_scores()` will need to be added to `Scoreboard` class.

### Step 13 - Loading the Scoreboard

It is time to load the scoreboard from the scores file before the user plays the game. Since the CSV format is used, it's actually quitte easy to load the scores from the file.

We will need to take the players into account for the scores. For example we should not create a new player object if the player already exists in the scoreboard. All scores of the same player should reference the same player object.

To be able to create a `Score` object based on a player and a score we will also need to add a second constructor to `Score`.

We should make a destructor for Scoreboard that deletes the Player objects that were created on the heap but we have a problem here that we will need to address in the next step.

### Step 14 - Player Problem

We created a problem here. A player object exists in the game that can be references by score objects in the scoreboard (newly added scores). Next to that the other scores reference player objects that were created on the heap inside the Scoreboard. If the scoreboard is destructed, we are obligated to delete the players on the heap. But this cannot be done for the scores that reference the player in the Game. This would cause undefined behavior (thats an object on the stack).

What we require is a single place where the player objects are created and destroyed (all of them). We could do this in the Scoreboard but it's less logical because that would mean that the Scoreboard would even need to track players that don't even have a scoreboard entry yet.

A better option is to create a `PlayerManager` class that tracks all players and creates a new player if required. We inject a pointer to this object in both `Game` and `Scoreboard`.

This also requires some refactoring of the main.

### Step 15 - Sorting and Limiting the Scores

For the moment scores are not sorted in the `Scoreboard`. There is also no limit on how much scores can be added to the scoreboard.

The fun thing here is that our `Score` objects are stored in an `std::vector` which alsready has a `sort()` method. There is however a small catch here. `std::vector` does not know how to sort `Score` objects. This problem can however be overcome by supplying a comparator method that needs to return `true` or `false` as an answer to the question: is `first` score smaller than `second` score.

A basic example can be found at [http://www.cplusplus.com/reference/algorithm/sort/](http://www.cplusplus.com/reference/algorithm/sort/).

Let's also add a `comparators` directory below `lib` as a start for adding some hierarchy to our files.
