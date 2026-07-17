#include "Dice.h"
#include <cstdlib>
#include <ctime>
#include<random>
 
// TODO: Implement rollDice().
// - Should return a random integer between 1 and 6, inclusive.
// - Think carefully about where to seed the random number generator.
//   If you seed it INSIDE this function, what happens every time it's called?
 
int RandomGen (int sides)
{
    int value_return = std::rand()%sides;
    return value_return;
}
int RollDice() {
    // TODO: replace this placeholder
    int roll_result = RandomGen(7);
    if(roll_result == 0)
    {
        roll_result ++;
    }
    return roll_result;
}