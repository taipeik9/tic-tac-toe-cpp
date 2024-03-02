#ifndef UTILS_H
#define UTILS_H

namespace tictactoe
{
  bool inputIntRange(int min, int max, int &userInput);
  bool validateStringInput(char *input, int maxSize);
  bool validateCharInput(char &input);
}

#endif