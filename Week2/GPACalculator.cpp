#include<iostream>

int main()
{
  int entered_credits = 0;
  int total_credits = 0; 
  int amount_of_classes_taken = 0;
  float total_credit_points = 0;
  std::string letter_grade = " ";
  float grade_point_average = 0;
  std::string Grades[13] = {"A+","A","A-","B+","B","B-","C+","C","D","F","WU","FIN","FAB"};
  int switch_condition = -1; 
  std::string user_decision = " ";

  std::cout << "Welcome to the Hunter GPA Calculator, You will be asked to provide the number of credits" <<std::endl;
  std::cout << "Then you will be asked to provide the letter grade, once those two values have been inputted, it will display the result" <<std::endl;

  while(true)
  {
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
    total_credits = total_credits += entered_credits;
    std::cout << "Please enter a letter grade"<<std::endl;
    std::cin  >> letter_grade;
    while(true)
    {
      for(int count = 0; count < 13; count ++)
      {
        std::cout << Grades[count];
        if(letter_grade == Grades[count])
        {
          switch_condition = count;
          
        }
      }
      if(switch_condition == -1){
      std::cout << "Invalid letter grade, please enter a new letter grade" << std::endl;
        std::cin >> letter_grade;
      }
      else
      {
        break;
      }
    }
    amount_of_classes_taken ++;
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
    grade_point_average = (total_credit_points/total_credits);
    std::cout << "Total Classes Taken: " << amount_of_classes_taken << std::endl;
    std::cout << "Grade Point Average: " << grade_point_average <<std::endl;

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
      break;
    }
  }
  return 0;
}