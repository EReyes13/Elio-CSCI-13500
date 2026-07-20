#include<iostream>
#include<fstream>
#include<string>

int main()
{
    int count = 0;
    std::string file_name = {};
    std::string word_to_replace = {};
    std::string new_word = {};
    std::string output_file = {};

//asks for input and attempts to open the file
    std::cout << "Please enter the file name you wish to input"<<std::endl;
    std::cin >> file_name;
    std::ifstream FileReaderObject(file_name);
    //Checks if the file opened successfully. If not, ask for another file
    while(!FileReaderObject.is_open())
    {
        std::cout << "File Not Found! Please input another file" <<std::endl;
        std::cin >> file_name;
        std::ifstream FileReaderObject(file_name);
    }
    //asks for the name of the output file and attempts to create the text file.
    std::cout << "Please input the name of the ouput file"<<std::endl;
    std::cin >> output_file;
    std::ofstream OutPutFile(output_file);
    if(!OutPutFile)
    {
        std::cout << "Problem creating a file" <<std::endl;
        return 1;
    }
    //asks the user what word they would like to replace the target word with.
    std::cout << "Please enter the word you wish to search and the word you wish to replace it with"<<std::endl;
    std::cin >> word_to_replace,new_word;

    //tracks the current line and word in the text file
    std::string current_line = {};
    std::string current_word = {};
    
    //gets every line in teh file and puts it to the current line
    while(std::getline(FileReaderObject, current_line))
    {
        //goes through every letter in the text and if it finds a space or newline, it considers it a word and performs the necessary checks
        for(char i :current_line)
        {
            if(i == ' ' or i == '\n')
            {
                //if the word made matches the word the users wants to replace it, it replaces it then outputs it to the file and increases the count
                if(current_word == word_to_replace)
                {
                    current_word = word_to_replace;
                    OutPutFile << current_word;
                    count++;
                    current_word.clear();
                }
                else
                {
                    OutPutFile << current_word;
                    current_word.clear();
                }       
            }
            current_word += i;
        }
        
        OutPutFile << "\n";
    }
    std::cout << "The word: "<<word_to_replace <<"Has been replaced "<<count<<" times"<<std::endl;
    std::cout << "Text has been outputted to "<<output_file<<".txt"<<std::endl;
    FileReaderObject.close();
    OutPutFile.close();
    return 0;
}