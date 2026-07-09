#include<iostream>
void recursion(int value_one, int value_two, int n_value, int count)
{
    int output = value_one + value_two;
    std::cout << output <<std::endl; 
    if(n_value == 15 || count == 20)
    {
        return;
    }
    count ++;
    std::cout <<"count: "<< count<<std::endl;
    recursion(value_two, output, (n_value +1),count);
}

int main()
{
int counter = 1;
int n_position = 2;
int n_zero = 0;
int n_one = 1;
recursion(n_zero,n_one,n_position, counter);
return 0;
}