#include <iostream>

// Reminder: Information about functions is on the specification PDF

void Print2DArray(const int matrix_local[][3], const int matrix_local_rows_total){

    // Function_Start message to terminal
    std::cout << "Start of Function: Print2DArray" << std::endl; 

    // Body of the function. Do your magic!
    //This checks each element of the matrix and if certain criteria is met, it prints certain characters and patterns.
    for(int count_x = 0; count_x < matrix_local_rows_total; count_x++)
    {
        for(int count_y = 0; count_y < matrix_local_rows_total; count_y++ )
            {
                if(count_y == 0)
                {
                    std::cout << "[" << matrix_local[count_x][count_y] << "|";
                }
                else if (count_y == matrix_local_rows_total - 1)
                {
                    std::cout << matrix_local[count_x][count_y] << "]"; 
                }
                else
                {
                    std::cout << matrix_local[count_x][count_y] << "|";
                }
            }
            std::cout << std::endl;
    }
    // Function_End message to terminal
    std::cout << "end of function: Print2DArray"  <<std::endl;
}

void MatrixAddition(const int matrix_one[][3], const int matrix_one_rows_total,
                    const int matrix_two[][3], const int matrix_two_rows_total)
    {
        //This matrix will get passed to the Print Matrix function.
        int resulting_matrix[][3] = {{0,0,0},{0,0,0},{0,0,0}};
        std::cout <<"Start of Function: Matrix Addition" << std::endl;
        for(int count_x = 0; count_x < matrix_one_rows_total; count_x ++)
        {
            for(int count_y = 0; count_y < matrix_one_rows_total; count_y++)
            {
                //this makes the corresponding element in the resulting matrix equal to the sum of both matrix values at the specified location.
                resulting_matrix[count_x][count_y] = matrix_one[count_x][count_y] + matrix_two[count_x][count_y];
            }
        }

        std::cout <<"End of Function: Matrix Addition" << std::endl;
        //Prints resulting matrix.
        Print2DArray(resulting_matrix,matrix_one_rows_total);
    }

void TransposeMatrix(const int matrix_local[][3], const int matrix_local_rows_total){
    // Function_Start message to terminal
    std::cout << " Start of Function: Transpose Matrix: " <<std::endl;
    // body of the function
    int row_count = matrix_local_rows_total;
    //This finds how much columns are in the matrix 
    int size_col_one = sizeof(matrix_local[0])/sizeof(matrix_local[0][0]);
    //This creates an empty array with the row and column dimensions inverted. 
    int resulting_matrix[][3] = {{0,0,0},{0,0,0},{0,0,0}};
        //I did count a and b instead of x and y since they are being used interchangeabely.
        for(int count_a = 0; count_a < matrix_local_rows_total; count_a++)
        {
            for(int count_b = 0; count_b < size_col_one;count_b ++)
            {
                resulting_matrix[count_a][count_b] = matrix_local[count_b][count_a];
            }
        }
        //I could print with non squares if the input parameter of Print2DArray alllowed for it.
        // Print2DArray(resulting_matrix,size_col_one);

    // display resulting matrix
    // if the dimension of the resulting matrix doesn't match the print function, you could do it manually here
    // or modify the parameter of the print function so it doesn't cause errors
    for(int count_x = 0; count_x < matrix_local_rows_total; count_x++)
{
    for(int count_y = 0; count_y < matrix_local_rows_total; count_y++ )
        {
            if(count_y == 0)
            {
                std::cout << "[" << matrix_local[count_x][count_y] << "|";
            }
            else if (count_y == matrix_local_rows_total - 1)
            {
                std::cout << matrix_local[count_x][count_y] << "]"; 
            }
            else
            {
                std::cout << matrix_local[count_x][count_y] << "|";
            }
        }
        std::cout << std::endl;
}

    // Function_End message to terminal 
    std::cout << " End of Function: Transpose Matrix" << std::endl;
}

void Determinant(const int matrix_local[][3], const int size){
    // Function_Start message to terminal
    std::cout << "Start of function: Determinant." <<std::endl;
    // check for valid dimensions
    if(size > 3)
    {
        std::cout<< "Invalid Dimensions" << std::endl; 
        return;
    }


    // body of the function 
    //values used in the final equation to find the determinant.
    int value_a = 0;
    int value_b = 0;
    int value_c = 0;
    //the determinant value that will be printed.
    int determinant = 0;
    //the calcaulations to find the determinant of a 3X3 matrix.
    value_a = (matrix_local[1][1] * matrix_local[2][2]) - (matrix_local[2][1] * matrix_local[1][2]);
    value_b = (matrix_local[0][1]*matrix_local[2][2]) - (matrix_local[2][1]*matrix_local[0][2]);
    value_c = (matrix_local[0][1]*matrix_local[1][2])-(matrix_local[1][1]*matrix_local[0][2]);
    determinant = value_a - value_b + value_c;

    //Troubleshooting purposes std::cout << value_a << value_b <<value_c <<std::endl;

    // print the determinant value on the terminal
    std::cout << determinant <<std::endl;

    // Function_End message to terminal
    std::cout << "end of function: Determinant" <<std::endl;
}

void SearchValue(const int matrix_local[][3], const int rows, const int target){
    // Function_Start message to terminal 
    std::cout << "start of function: SearchValue" << std::endl;
    // body of the function
    //is determined by if the target value is found
    bool found = false;
    //coordinates of where the target vlaue was foun 
    int position_x = 0;
    int position_y = 0;
    for(int count_x = 0; count_x < rows;count_x++)
    {
        for(int count_y = 0; count_y < rows; count_y++)
        {
            if(matrix_local[count_x][count_y] == target)
            {
                position_x = count_x;
                position_y = count_y;
                found = true;
            }
        }
    }
        // found  or not
    if(found)
    {
        std::cout <<"found " << target << " at [" <<position_x << "][" <<position_y << "]" <<std::endl; 
    }
    else
    {
        std::cout << target << "not found" <<std::endl;
    }
    // Function_End message to terminal
    std::cout << "end of function: SearchValue" <<std::endl;
}

void MatrixMultiplication(const int matrix_a[][3], const int matrix_b[][3], 
                    const int rows_a, const int cols_a, 
                    const int rows_b, const int cols_b){
    
    // Function_Start message to terminal
    std::cout << "Start of function : MatrixMultiplication" <<std::endl;
    
    // check for valid arrays
    if(rows_a != cols_a || rows_b != cols_b)
    {
        std::cout << "Invalid dimensions"<<std::endl;
        return;
    }


    // Body of the function
    //array to be printed in terminal
    int resulting_array[][3] = {{0,0,0},{0,0,0},{0,0,0}};
    //holds the value of the sum of the multiplication for each space in the resulting array.
    int placeholder_sum = 0;
    //counts the x axis
    for(int count_x = 0; count_x < rows_a; count_x++ )
    {
        //counts the y axis
        for(int count_y = 0; count_y < 3; count_y++ )
        {
        placeholder_sum = 0;
        //counts the x axis temporarily to hold the complex multiplication in place.
        for (int x_position = 0; x_position < cols_a; x_position++ )
        {
            placeholder_sum = placeholder_sum += ((matrix_a[count_x][x_position]*matrix_b[x_position][count_y]));
        }
         resulting_array[count_x][count_y] = placeholder_sum;

        }
    }
    // Print resulting matrix
    Print2DArray(resulting_array,rows_a);
    // Function_End message to terminal
    std::cout << "end of function : Matrix Multiplication" <<std::endl;
}

int main(){
    // Use these two matrices for basic testing.

    int testing_matrix_one[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    int testing_matrix_two[3][3] = {
        {12,65,82},
        {83,2,8},
        {10,96,67}
    };


// Not used in this class, but it is nice to know other ways to find the size of primitive array.
// This method below is similar to how you will find the size of vectors (future material)
    // DO NOT USE IN THIS PROJECT FUNCTION, but you could test it yourselves.
    // int size_row_one = std::size(testing_matrix_one);
    // int size_col_one = std::size(testing_matrix_one[0]);


    // This is a way to find the dimensions of an array without hardcoding values.
    // It dynamically reflects the array's actual declared size, so if you change
    // the array dimensions, the calculation updates automatically.
    //
    // How it works:
    //
    // To find the number of ROWS:
    //   sizeof(testing_matrix_one)      = total bytes of the whole array = 3*9*4 = 108 bytes
    //   sizeof(testing_matrix_one[0])   = total bytes of one row         = 1*9*4 =  36 bytes
    //   108 / 36 = 3 rows
    
    int size_row_one = sizeof(testing_matrix_one)/sizeof(testing_matrix_one[0]);
    int size_row_two = sizeof(testing_matrix_two)/sizeof(testing_matrix_two[0]);

    // To find the number of COLUMNS:
    //   sizeof(testing_matrix_one[0])      = total bytes of one row          = 1*9*4 = 36 bytes
    //   sizeof(testing_matrix_one[0][0])   = total bytes of one element(int) = 1*4   =  4 bytes
    //   36 / 4 = 9 cols
    
    int size_col_one = sizeof(testing_matrix_one[0])/sizeof(testing_matrix_one[0][0]);
    int size_col_two = sizeof(testing_matrix_two[0])/sizeof(testing_matrix_two[0][0]);

    std::cout << "row: " << size_row_one<< " col: " << size_col_one<< std::endl << std::endl;

   Print2DArray(testing_matrix_one, size_row_one);
    MatrixAddition(testing_matrix_one,size_row_one,testing_matrix_two,size_row_two);
    TransposeMatrix(testing_matrix_one,size_row_one);
    Determinant(testing_matrix_one, size_row_one);
    SearchValue(testing_matrix_one, size_row_one, 5);
    MatrixMultiplication(testing_matrix_one,testing_matrix_two,size_row_one,size_row_two,size_col_one,size_col_two);

    return 0; 
}