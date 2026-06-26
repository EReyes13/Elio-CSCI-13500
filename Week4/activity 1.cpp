#include<iostream>
#include<vector>


int main()
{
    std::vector<std::vector<int>> grid = 
    {
      {1,2,3},
      {3,1,2},
      {2,3,1}  
    };
    std::vector<int> check = {};
    bool valid = true;
    // std::vector<int> test = {1,2,3};
    for(int count_x = 0;count_x <grid.size();count_x++)
    {
        for(int count_y = 0; count_y < grid[0].size();count_y++)
        {
            for(int check_count = 0; check_count <=check.size();check_count++)
            {
                if(grid[count_x][count_y] == check[check_count])
                {
                    valid = false;
                }
                else
                {
                    check.push_back(grid[count_x][count_y]);
                }
            }
            check.clear();
        }        
    }
    if(!valid)
    {std::cout << "this matrix is not valid" <<std::endl;}
    else
    {
        std::cout <<"this matrix is valid" <<std::endl;
    }
    
    return 0;
}