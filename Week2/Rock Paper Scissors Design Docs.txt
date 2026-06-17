Program Name: ElioRockPaperScissors.cpp

Purpose: 
Simple game of Rock Paper Scissors with a modifier twist.

Inputs: 
   - User choice of rock paper or scissors
   - What modifier do they want (if any)
   

Output: Game Results, then winner based on certain conditions.

Variables:
-int player_score Tracks the player's score  
-int bot_score  Tracks the bot's score
-string player_move Decides what choice the user makes for Rock Paper Scissors
-int bot_move  Determines the bot's move
-string bot_pick The bot's choice for Rock Paper Scissors
-string List bot_choices The potential choices the bot can make
-string user_modifier Determines what modifiers are used(or none)
Key Design Choices:
 - I added more output to show the current scores, more possible inputs, and slight specification.
 - I added modifiers that allow the user to either risk double points for the winner or to play it safe and negate any points earned that round.
 - I added one input validation
Program Steps:
 -First, the programs asks the user to choose between Rock,Paper, or Scissors. 
 -Once the user inputs their choice(after input verification), the program asks the user to choose a modifier or no modifier at all.
 -Once the user chooses their answer, a random number is generated from 1 to 3. This number decides what the bot chooses based on the list options and what choice corresponds to the random number.
 -After the choice is made, the program checks both the user and bot's choice and decides a winner based on the choices.
 - If the risk modifier was chosen, two points were awarded. Else, only one point is awarded.
 -If the safe modifier was chosen, no points are awarded despite the outcome.
 -If either the player or the bot had at least a certain amount of points, the program deems them as the winner and ends the program.  
Functions:
 main(): Holds the Rock Paper Scissors game.

 Sample Input/Output:
 
 Input:
 -Rock
 -None
 Output:
 Player Wins!

Test Cases:
Choose rock, paper or scissor: 
Rock
Bot Chose: Scissor
Player Wins!
Player Score: 2
Bot Score: 0

Choose rock, paper or scissor: 
Paper
Bot Chose: Scissor
Bot wins.
Player Score: 1
Bot Score: 1