#include <iostream>
#include <cstdlib> // Random number library
#include <ctime> // Time
#include<math.h>
#include <algorithm>
#include <vector>

using namespace std;

// Input: Takes an input that tells the function how long to make the target number
// Output: Outputs a random number of a specified length that has unique digits. 
int generateTarget(int length) {
  int target = 0;
  // Decides the seed based on the time the program was executed
  srand((unsigned) time(NULL));
  // initializes an empty vector that will contain all the digits that have been used
  vector<int> used;
  // creates a random number in the range [1,9]
  int random = 1 + (rand() % 9);

  for (int i = 0; i < length; i++){
    // checks if the random number has been used before, generates a new number until it finds a digit that hasn't been used yet
    while (count(used.begin(), used.end(), random)){
      random = 1 + (rand() % 9);
    }
    // Inserts the random number into the used number vector
    used.insert(used.begin(), random);
    // Create the target
    target += random * pow(10, i);
  }

  return target;
}

int main() 
{
  // Generates the target for this game
  int targetLength;
  targetLength = 4;

  int target = generateTarget(targetLength);
  cout << target << endl;

  return 0;
}