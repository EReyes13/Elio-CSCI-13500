#pragma once
struct Node
{
    int value;
    Node* next;

    Node(int passed_value)
    {
        value = passed_value;
        next = nullptr;
        
    }
};

class LinkedList
{
    public:
    LinkedList();
    void InsertNode(const int value)
    {

    }

    private:
    int size_;
    Node* head_;
};