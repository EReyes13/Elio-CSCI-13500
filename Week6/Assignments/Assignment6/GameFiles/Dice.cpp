#include "Dice.h"
#include <cstdlib>
#include <ctime>
#include<random>
 
// TODO: Implement rollDice().
// - Should return a random integer between 1 and 6, inclusive.
// - Think carefully about where to seed the random number generator.
//   If you seed it INSIDE this function, what happens every time it's called?
 
int RollDice() {
    // TODO: replace this placeholder
    int roll_result = std::rand()% 7;
    return roll_result;
}