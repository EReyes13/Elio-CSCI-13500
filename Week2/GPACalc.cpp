#include<iostream>

int main()
{
  int entered_credits = 0;
  //total_credits tracks the sum of all entered_credits for as long as the user wants to continue usign the program.
  int total_credits = 0; 
  //this tracks how many classes have been taken, which increases each time the user enters the credits and letter grade.
  int amount_of_classes_taken = 0;
  //stores the total amount of credit points based on the values that are determined by the switch statement
  float total_credit_points = 0;
  std::string letter_grade = " ";
  //Responsible for the rounding aspect of the calculations
  int grade_point_average_rounded = 0;
  //Final output after all calculations are done.
  float grade_point_average = 0;
  //List of possible grades according to the Hunter Grading Chart.
  std::string Grades[13] = {"A+","A","A-","B+","B","B-","C+","C","D","F","WU","FIN","FAB"};
  //This variable allows me to convert the possible grade in the Array into a int value 
  //that can be used in the switch case which will determine the Credit Point that will be used in the later calculation.
  //Default value is -1 so it will not accidentaly trigger a case if the user enters an invalid Letter Grade.
  int switch_condition = -1; 
  //This will determine if the user wants to keep going.
  std::string user_decision = " ";

  std::cout << "Welcome to the Hunter GPA Calculator, You will be asked to provide the number of credits" <<std::endl;
  std::cout << "Then you will be asked to provide the letter grade, once those two values have been inputted, it will display the result" <<std::endl;
  //This giant while loop is what allows for the user to keep going if they want to. 
  //At the end of the while loop, the user has the option to keep going. 
  //If they choose no, then it will break out of this while loop. 
  while(true)
  {
    //Input validation to make sure no error bny user input can occur.
      while(true)
    {
      std::cout << "Please enter the number of credits: " <<std::endl;
      std::cin >> entered_credits;
      if(std::cin.fail() || entered_credits >= 10)
      {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Invalid credits, Please Try Again" <<std::endl;
      }
      else
      {
        break;
      }
    }
    //Adds the user inputted credits to the total amount of credits in that session.
    total_credits = total_credits += entered_credits;
    std::cout << "Please enter a letter grade"<<std::endl;
    std::cin  >> letter_grade;
    while(true)
    {
      //This looks through the Array and tries to match the inputted string to the Array. 
      //If it finds a match, the switch condition variable is changed to the location in the Array of that Grade,
      //which will then be used in the switch statement to determine the Credit Point.
      for(int count = 0; count < 13; count ++)
      {
        //Used for debugging Purposes. std::cout << Grades[count];
        if(letter_grade == Grades[count])
        {
          switch_condition = count;
          
        }
      }
      //If it did not find a match, the value will be default, which is -1. If this occurs, then it will ask to enter Another Letter Grade.  
      if(switch_condition == -1){
      std::cout << "Invalid letter grade, please enter a new letter grade" << std::endl;
        std::cin >> letter_grade;
      }
      else
      {
        break;
      }
    }
    //This increases the amount of class taken and will increase once per loop.
    amount_of_classes_taken ++;
    //This takes the Letter grade from the earlier for loop if it was succesful, and matches it to their respective case which determines
    //the credit point awarded.
    switch (switch_condition)
    {
    case 0:
    {
      total_credit_points = total_credit_points += (entered_credits * 4.00f);
      break;
    }
    case 1:
    {
      total_credit_points = total_credit_points += (entered_credits * 4.00f);
      break;
    }
    case 2:
    {
      total_credit_points = total_credit_points += (entered_credits * 3.70f);
      break;
    }
    case 3:
    {
      total_credit_points = total_credit_points += (entered_credits * 3.30f);
      break;
    }
    case 4:
    {
      total_credit_points = total_credit_points += (entered_credits * 3.00f);
      break;
    }
    case 5:
    {
      total_credit_points = total_credit_points += (entered_credits * 2.70f);
      break;
    }
    case 6:
    {
      total_credit_points = total_credit_points += (entered_credits * 2.30f);
      break;
    }
    case 7:
    {
      total_credit_points = total_credit_points += (entered_credits * 2.00f);
      break;
    }
    case 8:
    {
      total_credit_points = total_credit_points += (entered_credits * 1.00);
      break;
    }
    case 9:
    {
      total_credit_points = total_credit_points += (entered_credits * 0.00);
      break;
    }
    case 10:
    {
      total_credit_points = total_credit_points += (entered_credits * 0.00);
      break;
    }
    case 11:
    {
      total_credit_points = total_credit_points += (entered_credits * 0.00);
      break;
    }
    case 12:
    {
      total_credit_points = total_credit_points += (entered_credits * 0.00);
      break;
    }
    }
    //this does the final calculation and outputs it to the user.
    grade_point_average = (total_credit_points/total_credits);
    //these lines are responsible for rounding ot the nearest hundreth.
    grade_point_average_rounded = grade_point_average *1000;
    std::cout << grade_point_average_rounded;
    if((grade_point_average_rounded % 10) >= 5)
    {
      grade_point_average_rounded = (grade_point_average_rounded + 10)/10;
      std::cout << grade_point_average_rounded;
      //these two lines are seperate because if they are in the same line, the rounding would be to the nearest int instead.
      grade_point_average = grade_point_average_rounded;
      grade_point_average = grade_point_average /100;
    }
    std::cout << "Total Classes Taken: " << amount_of_classes_taken << std::endl;
    std::cout << "Grade Point Average: " << grade_point_average <<std::endl;

    //This allows the user to continue the while loop and enter more classes or break out the while loop and end the program
    std::cout << "Would you like to enter another class?";
    std::cin >> user_decision;
    while(user_decision != "Yes" && user_decision != "No")
    {
      std::cout << "Invalid Input, please type Yes or No"; 
      std::cin >> user_decision;
    }
    if(user_decision == "Yes")
    {
      switch_condition = -1;
    }
    else
    {
      std::cout <<"Thank you, Goodbye :)" <<std::endl;
      break;
    }
  }
  return 0;
}