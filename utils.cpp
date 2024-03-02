#include <iostream>
#include <cstring>
#include <limits>

#include "utils.h"

using namespace std;

namespace tictactoe
{
  bool inputIntRange(int min, int max, int &userInput)
  {
    bool isValid = false;
    cin >> userInput;

    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input. Please enter an integer: " << endl;
    }
    else if (userInput < min || userInput > max)
    {
      cout << "Out of range. Please enter a number between " << min << " and " << max << ". (inclusive): " << endl;
    }
    else
    {
      isValid = true;
    }

    return isValid;
  }

  bool validateStringInput(char *input, int maxSize)
  {
    cin.getline(input, maxSize);
    if (strlen(input) == 0 || strlen(input) >= maxSize)
    {
      cout << "Invalid input! Please enter a non-empty string with a maximum length of " << maxSize - 1 << " characters." << endl;
      return false;
    }
    return true;
  }

  bool validateCharInput(char &input)
  {
    cin >> input;
    if (cin.fail() || cin.peek() != '\n')
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Invalid input! Please enter a single non-empty character." << endl;
      return false;
    }
    return true;
  }
}