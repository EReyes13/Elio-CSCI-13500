#include <iostream>
#include <vector>


void removeCopies(std::vector<int>& data)
{

    // The vector is sorted in non-decreasing order.
    // Remove all duplicate values in-place so that
    // each value appears exactly once.
    //
    // Do not create another vector.
    // Modify the vector named "data" directly.
    //
    // Maybe two-pointer method? Hmm?
    // Hint: resize() function
    int current_number = 0;
    int placeholder = 0;
    int left_point = 0;
    int new_num = 0;
    for(int count = 0; count < data.size();count++)
    {
        left_point++;
        if(data[count] <= current_number)
        {
            while(data[placeholder] == current_number && placeholder < data.size() - 1)
            {
                placeholder++;
            }
            new_num = data[placeholder];
            data[count] = new_num;
            current_number = data[placeholder];
        }
        else
        {
            current_number = data[count];
        }
    }
    data.resize(current_number);
}

void isAnagram(std::string officer_name, std::string spy_name){

    // Write code to see if the spy name is an anagram of the officer name 
    // Maybe a vector of size 26? Hmm?
    std::vector<int> letters (127);
    if(officer_name.size() != spy_name.size())
    {
    std::cout <<"Imposter" <<std::endl;
    return;        
    }
    for(int count_one = 0; count_one < officer_name.size();count_one++)
    {
        letters[officer_name[count_one]]++;
    }
    for(int count_two =0;count_two < spy_name.size(); count_two++)
    {
        letters[spy_name[count_two]]--;
        if(letters[spy_name[count_two]] < 0)
        {
            std::cout << "imposter ahh " <<std::endl;
            return;
        }
    }
    std::cout <<"He is real" <<std::endl;
}

int main(){

    /*Use other test cases to make sure you program works*/
    std::vector<int> server = {1,1,2,2,2,3,3,4,5,6,6,6};

    /*Print out the original server vector before function called*/
     for (auto data : server){
        std::cout << data << " "; // 1,1,2,2,2,3,3,4,5,6,6,6
   }
   std::cout << std::endl;

    removeCopies(server);
    
   //Print out the modification of the server vector after function called*/
   for (auto data : server){
    std::cout << data << " ";
   }

    std::cout << std::endl;

    /****************************TEST ANAGRAM*************************************/

    isAnagram("syeda", "aysed"); // No imposter detected!
    isAnagram("angelo", "annabeth"); // IMPOSTER! IMPOSTER!

    return 0;

}

/*Part 2: The time complexity of the first function is O(n) since it goes through the array once.
(I do not know exactly what the time complexity of a while loop is).
The time complexity of the second function is O(n*m) since it goes through two different strings once
(it could be O(2n) if both strings were of equal length)*/
