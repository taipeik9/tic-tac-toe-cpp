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

  bool validateStringInput(char *input, int maxSize, char const *message)
  {
    cin.getline(input, maxSize);
    if (strlen(input) == 0 || strlen(input) >= maxSize)
    {
      cout << message << endl;
      return false;
    }
    return true;
  }

  bool validateCharInput(char &input)
  {
    char temp[50];
    if (!validateStringInput(temp, 50, "Must be a single, non-empty character. Please try again."))
      return false;

    if (temp[1] != '\0')
    {
      cout << "Input should be a single character. Please try again." << endl;
      return false;
    }
    input = temp[0];
    return true;
  }
}