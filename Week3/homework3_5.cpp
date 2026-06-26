#include<iostream>
#include<vector>
int main()
{
    //initialization of the template arrays.
    int value_grid[3][3] = {
    {0,0,0},
    {0,0,0},
    {0,0,0}};
    int value_grid_second[6][6] = {
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,0,0}};
    //Initialization of the Vector and related variables.
    std::vector<std::vector<int>> value_grid_vector = {
    {5,3,2},
    {4,6,5},
    {2,8,7}};
    std::vector<std::vector<int>> sum_results = {};
    std::vector<int> row_results = {};
    std::vector<int> column_results = {};
    int row_sum = 0;
    int column_sum = 0;
    int diagonal_sum = 0;
    int anti_diagonal_sum = 0;
    int center_value = 0;
    int final_sum = 0;

    /* Task 1
     for(int count_x = 0; count_x < 3;count_x++)
     {
         for(int count_y = 0;count_y < 3;count_y++)
         {
             if(count_y < (3 - count_x))
             {
                 value_grid[count_x][count_y] = 1;  
             }
             std::cout << value_grid[count_x][count_y];
         }
         std::cout << std::endl;
     }

     for(int count_x = 0; count_x < 6;count_x++)
     {
         for(int count_y = 0;count_y < 6;count_y++)
         {
             if(count_y < (6 - count_x))
             {
                 value_grid_second[count_x][count_y] = 1;  
             }
             std::cout << value_grid_second[count_x][count_y];
         }
         std::cout << std::endl;
     }*/

     /*Task 2

     for(int count_x = 0;count_x < 3;count_x++)
     {
        for(int count_y = 0; count_y < 3;count_y++)
        {
            if(count_y == count_x || count_y == (2 - count_x))
            {
                value_grid[count_x][count_y] = 1;
            }
            std::cout << value_grid[count_x][count_y];
        }
        std::cout << std::endl;
     }
      for(int count_x = 0;count_x < 6;count_x++)
     {
        for(int count_y = 0; count_y < 6;count_y++)
        {
            if(count_y == count_x || count_y == (5 - count_x))
            {
                value_grid_second[count_x][count_y] = 1;
            }
            std::cout << value_grid_second[count_x][count_y];
        }
        std::cout << std::endl;
     }   */

     /*Task 3
     for(int count_1 =0; count_1 < value_grid_vector.size();count_1++)
     {
        row_sum = 0;
        column_sum = 0;
        for(int count_2 = 0; count_2 < value_grid_vector.size();count_2++)
        {
            row_sum = row_sum += value_grid_vector[count_1][count_2];
            column_sum = column_sum += value_grid_vector [count_2][count_1];
        }
        row_results.push_back(row_sum);
        column_results.push_back(column_sum);
       // std::cout << row_sum << " " << column_sum <<std::endl; 
     }
     sum_results.push_back(row_results);
     sum_results.push_back(column_results);
     for(int result_count = 0; result_count < 2; result_count ++)
     {
        for(int result_position = 0; result_position < sum_results[0].size();result_position++)
        {
            std::cout << sum_results[result_count][result_position] << " ";
        }
        std::cout << std::endl;
     }*/

     for(int count_1 = 0;count_1 < value_grid_vector.size(); count_1++)
     {
        for(int count_2 = 0; count_2 < value_grid_vector[0].size(); count_2++)
        {
            if(count_2 == count_1)
            {
                diagonal_sum = diagonal_sum += value_grid_vector[count_1][count_2];
            }
            else if(count_2 == value_grid_vector[0].size() - (count_1 +1))
            {
                anti_diagonal_sum = anti_diagonal_sum += value_grid_vector[count_1][count_2];
            }
            else if(count_2 == count_1 && count_2 == value_grid_vector[0].size() - (count_1 + 1))
            {
                center_value = value_grid_vector[count_1][count_2];
            }
        }
     }
     final_sum = diagonal_sum += anti_diagonal_sum - center_value;
     std::cout <<final_sum <<std::endl;

    return 0;

}