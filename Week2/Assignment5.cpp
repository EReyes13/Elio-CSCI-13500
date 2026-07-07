#include<iostream>
#include<random>
#include<string>

//Gets the players choice of rock, paper, or scissor
std::string user_input()
{
    std::string user_input = "";
    std::cout << "Please make your choice of Rock, Paper, or Scissor" << std::endl;
    std::cin >> user_input;
    while(user_input != "Rock"&& user_input != "Paper" && user_input != "Scissor")
        {
            std::cout << "Invalid choice, please try again" <<std::endl;
            std::cin >> user_input;
        }
    return user_input;
}
//Generates the bot's choice
std::string bot_input()
{
    std::string bot_input = "";
    std::string bot_choices[3] = {"Rock","Paper","Scissor"};
    int bot_move = 0;
    bot_move = rand() % 3;
    bot_input = bot_choices[bot_move];
    return bot_input;
}
//Allows the player to select a modifier to  change the outcome, or choose none at all.
void modifier_decision(bool& risk, bool& safe)
{
    std::string choice = "";
    std::cout << "You are able to pick one of the following modifiers or none at all." << std::endl;
    std::cout << "Risk: doubles the point earned by the winner" << std::endl;
    std::cout << "Safe: Prevents any score from being added" << std::endl;
    std::cout << "None: No modifier will be selected" << std::endl;      
    std::cout << "What will you choose?" <<std::endl;
    std::cin >> choice;
    while(choice != "Risk" && choice != "Safe" && choice != "None")
    {
        std::cout << "Invalid choice, please choose again";
        std::cin >> choice;
    }
    if(choice == "Risk")
    {
        risk = true;
    }
    else if(choice == "Safe")
    {
        safe = true;
    }
}
//Decides who wins the round by comparing both choices and updates the score accordingly.
void turn_decider(std::string player_move, std::string bot_pick, int& player_score, int& bot_score, bool risk_option, bool safe_option)
{
    //checks if the safe option has not been selected.
    if(!safe_option)
        {
        // figure out the score 
        
        if (player_move == bot_pick){
            /* Do not know if this is even necessary.
            player_score += 0;
            bot_score += 0;
            */
           std::cout <<"Tie!" <<std::endl;
        }
        else if (player_move == "Rock" && bot_pick == "Scissor"){
            player_score++;
            //checks if the risk option was selected and adds an extra point if it was.
            if(risk_option)
            {
                player_score ++;
            }
            std::cout << "Player wins this round!" <<std::endl;
        }
        else if (player_move == "Paper" && bot_pick == "Rock"){
            player_score++;
            if(risk_option)
            {
                player_score ++;
            }
            std::cout << "Player wins this round!" <<std::endl;
        }
        else if (player_move == "Scissor" && bot_pick == "Paper"){
            player_score++;
            if(risk_option)
            {
                player_score ++;
            }
            std::cout << "Player wins this round!" <<std::endl;
        }
        else{
            std::cout << "Bot wins this round." <<std::endl;
            bot_score++;
            if(risk_option)
            {
                bot_score ++;
            }
        }
        }
        std::cout << "Player Score: " << player_score <<std::endl;
        std::cout << "Bot Score: " << bot_score <<std::endl;
}
//Checks for win condition, I find it better for it to be first to 4 rather than 4 rounds since I don't really like ties.
void check_win(const int user_score,const int bot_score, bool& game_loop)
{
    if(user_score >= 4)
    {
        std::cout << "player wins! the game" <<std::endl;
        game_loop = false;
    }
    else if(bot_score >= 4)
    {
        std::cout  << "Bot wins the game" <<std::endl;
        game_loop = false;
    }
}
//resets the variables for the next round.
void reset_stat(std::string& user_input, std::string& bot_input, bool& risk,bool& safe)
{
user_input = "";
bot_input = "";
risk = false;
safe = false;
}
//main. Just main.
int main()
{
    //variables that are necessary for the game including player choices and scores.
    bool game_active = true;
    std::string user_choice = "";
    std::string bot_choice = "";
    int user_score = 0;
    int bot_score = 0;
    bool risk_option = false;
    bool safe_option = false;
    //Gameplay loop
    while(game_active)
    {
    user_choice = user_input();
    bot_choice = bot_input();
    modifier_decision(risk_option, safe_option);
    std::cout << "Bot chose: " << bot_choice <<std::endl;
    turn_decider(user_choice,bot_choice,user_score,bot_score,risk_option,safe_option);
    check_win(user_score,bot_score, game_active);
    reset_stat(user_choice,bot_choice,risk_option,safe_option);
    }
    return 0;
}