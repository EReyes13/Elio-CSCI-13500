#include <iostream>
#include <random>


int main(){

    // start game (declare variables)
    int player_score = 0;
    int bot_score = 0;
    std::string player_move = "";
    int bot_move = 0;
    std::string bot_pick = ""; 
    //Easier way to have the bot choose instead of if else statements(not too big of a difference but who cares).
    std::string bot_choices[3] = {"Rock","Paper","Scissor"}; 
    std::string user_modifier = "";

    //optional modifiers that the user can choose.
    bool risk_option = false;
    bool safe_option = false;
    // game loop
    for (int rounds = 0; rounds < 4; rounds++)
    {
        //Reset modifier variables
        safe_option = false;
        risk_option = false;
        // check for early winner 
        if (player_score >= 3 || bot_score >= 3){
            break;
        }

        // ask for user input 
        std::cout << "Choose rock, paper or scissor: " <<std::endl;
        std::cin >> player_move;

        

        //simple input validation. I rather have three coniditons for the while loop than use a for loop for checking from a list.
        while(player_move != "Rock"&& player_move != "Paper" && player_move != "Scissor")
        {
            std::cout << "Invalid choice, please try again" <<std::endl;
            std::cin >> player_move;
        }

        //Allowing the player to choose  a modifier
        std::cout << "You are able to pick one of the following modifiers or none at all." << std::endl;
        std::cout << "Risk: doubles the point earned by the winner" << std::endl;
        std::cout << "Safe: Prevents any score from being added" << std::endl;
        std::cout << "None: No modifier will be selected" << std::endl;  
        std::cin >> user_modifier;
        while(user_modifier != "Risk" && user_modifier != "Safe" && user_modifier != "None")
        {
            std::cout << "Invalid choice, please try again" <<std::endl;
            std::cin >> user_modifier;
        }
        //Changes the bool responsible for the modifiers
        if(user_modifier == "Risk") {risk_option = true;}
        else if(user_modifier == "Safe") {safe_option = true;}
        else{user_modifier = false;
        risk_option = false;}

        // generate bot input 
        //I chose to use a list rather than the if else statement since it is more efficient.
        bot_move = rand() % 3;
        
        bot_pick = bot_choices[bot_move];
        /*
        if (bot_move == 0){
            bot_pick = "Rock";
        }
        else if (bot_move == 1){
            bot_pick = "Paper";
        }
        else{
            bot_pick = "Scissor";
        }
            */
        std::cout << "Bot Chose: " << bot_pick << std::endl;
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
            if(risk_option)
            {
                player_score ++;
            }
            std::cout << "Player Wins!" <<std::endl;
        }
        else if (player_move == "Paper" && bot_pick == "Rock"){
            player_score++;
            if(risk_option)
            {
                player_score ++;
            }
            std::cout << "Player Wins!" <<std::endl;
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
    // Declare winner or tie
    
    if (player_score > bot_score){
        std::cout << "Player wins the game!" << std::endl;
    }
    else if (bot_score > player_score){
        std::cout << "Bot wins the game. Better luck next time." << std::endl;
    }
    else{
        std::cout << "Tie! Try again." << std::endl;
    }
    

}