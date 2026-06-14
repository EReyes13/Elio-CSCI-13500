#include<iostream>

int main ()
{
  float first_number = 0;
  float second_number = 0;
  float calculation_result = 0;;
  char math_symbol = ' ' ;
  char repeat_calculation = ' ';
    std::cout << "Hello, please input the first value" << std::endl;
    std::cin >> first_number;
    std::cout << "please input the operation you wish to perform "<< std::endl;
    std::cin >> math_symbol;
    std::cout <<"please input the second value" << std::endl;
    std::cin >> second_number;
    while (math_symbol != '+' && math_symbol != '/' && math_symbol != '-' && math_symbol != '*' )
    {
      std::cout << "Invalid Operation, please select another operation" << std::endl;
      std::cin >> math_symbol; 
    }
    
    switch (math_symbol)
    {
    case '+':
      calculation_result = first_number + second_number;
      std::cout << "Result: " << calculation_result << std::endl;
      break;
      case '-':
    {
      calculation_result = first_number - second_number;
      std::cout << "Result: " << calculation_result << std::endl;
      break;
    }
    case '/':
    {
      while(second_number == 0)
      {
        std::cout << "Error: Division by zero is not allowed, please try again" << std::endl;
        std::cout << "please input a new value" << std::endl;
        std::cin >> second_number;
      }

        calculation_result = first_number/second_number;
        std::cout << "Result: " << calculation_result << std::endl;
      
      break;
    }
    case '*':
    {
      calculation_result = first_number * second_number;
      std::cout << "Result: " << calculation_result << std::endl;
      break;
    }
    }
    
    
    std::cout << "would you like to perform another calculation? input Y for yes or N for no" << std::endl;
    std::cin >> repeat_calculation;
    
    while(repeat_calculation != 'Y' && repeat_calculation != 'N')
    {
      std::cout << "Invalid Choice, please try again" << std::endl;
      std::cout << "would you like to perform another calculation? input Y for yes or N for no" << std::endl;
      std::cin >> repeat_calculation;

    }
    if(repeat_calculation == 'Y')
      {
        main();
      }
    else if(repeat_calculation == 'N')
    {
      std::cout<< "Goodbye :)";
    }
    
    return 0;
}