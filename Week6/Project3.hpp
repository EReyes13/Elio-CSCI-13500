#pragma once

struct Node
{
    int value_;
    Node* next_;
    
    Node(int passed_value)
    {
        value_ = passed_value;
        next_ = nullptr;
    }
};

class LinkedList
{
    //function declarations will go here
    public:
    LinkedList();
    ~LinkedList();
    void InsertNode(const int value);
    void InsertNodeAtFront(const int value);
    bool Contains(const int value) const;
    bool Remove(const int position);
    void PrintValues() const;
    void PrintAddresses() const;
    int GetValueAtPosition(const int position) const;
    void InsertNodeAt(const int value, const int position);//missing still.
    int GetSize() const;
    LinkedList* ReverseList();
    LinkedList* MergeIntertwine(const LinkedList& second_list);
    //missing ReverseList,InsertNodeAt,and MergeIntertwine.

    //static variable declaration will go here
    private:
    int size_;
    Node* head_;
    Node* last;

};