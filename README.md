# tictactoecpp

Tic Tac Toe game in commandline made using C++

## Notes on Game and Explanation

Compilation with g++

```
g++ -Wall -g -std=c++11 main.cpp player.cpp game.cpp utils.cpp -o tictactoe && ./tictactoe
```

The game is played between two players. The user decides on how many games to play, and what symbols represent each player. It doesn't need to be Xs and Os. In the leaks-report.txt file you can see a sample output with some demonstration of error handling, like the user input handling and the game logic. At the end of playing all of the games a summary is displayed with how many wins each player recieved and the boards of each game and results are reprinted so the user can see the history of the entire match, with three potential outcomes: P1 wins, P2 wins or draw.

Comprised of two classes:

- Player Class (player.cpp)
- Game Class (game.cpp)

Utils to deal with user input.

### Game Class

Dynamically allocated number of games decided by the user upon intializing the game in the setGame() function.

This class tracks the history of the boards of each game and it keeps an array of both players.

There are a few functions that are used in conjuction with eachother to comprise the game logic.

### Player Class

This holds the player name, symbol and number of wins. The player's name is a dynamically allocated C-style character array.

It uses getter functions to access the private members to maintain encapsulation along with operator overloading for incrementing the player wins.

The set function validates the desired input for the data members and then sets them to the corresponding members, dynamically allocating memory for the name member.

## Conclusion

I had a lot of fun creating this project, no tutorials were used to create it, just the knowledge from my Object Oriented Programming class at Seneca College. This is a demonstration of my understanding of Object Oriented Programming and its fundamentals, along with the game logic and general C++ knowledge such as dynamic memory allocation, operator overloading, class structure, user input validation and more.
