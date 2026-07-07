#include<iostream>

struct Node
{
    std::string name = {};
    Node* next_node = nullptr;
    Node(std::string user_data)
    {
        this -> name = user_data;
    }
};

int main()
{
    Node head("Start");
    Node* current_node = &head;
    std::string user_input = 0;
    while(std::cin >> user_input)
    {
        if(std::cin.fail())
        {
            break;
        }

        current_node -> next_node = new Node(user_input);
        current_node = current_node -> next_node;
    }
    // Node* head = new Node("Starting");
}