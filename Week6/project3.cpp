#include<iostream>
#include "Project3.h"

//initial constructor
LinkedList::LinkedList()
{
    size_ = 0;
    head_ = nullptr;
}

//adds a node at the end of the list
void LinkedList::InsertNode(const int value)
{
    if(head_ == nullptr)
    {
        //makes a new node at the front to act as the head if the list is empty
        head_ = new Node(value);
        //increases size var in the class
        size_ ++;
        //makes the last node in the list the head since it is the only node
        last = head_;
    }
    //makes the next node a new node with the inputted value 
    Node* new_last_ = new Node(value);
    //sets the next variable to the new node made
    last->next_ = new_last_;
    //sets the new node as the last node in the list
    last = new_last_;
    //increases size
    size_++;
}

void LinkedList::InsertNodeAtFront(const int value)
{
    //makes a new node
    Node* new_head = new Node(value);
    //makes the next node the head of the list.
    new_head->next_ = head_;
    //makes the head of the list the new head created.
    head_ = new_head;
    size_++;
}

bool LinkedList::Contains(const int value)const
{
    Node* current_node = head_;
    //searches the list
    while(current_node)
    {
        //checks if the value in the node is equal to the value parameter
        if(current_node->value_ == value )
        {
            return true;
        }
        current_node = current_node->next_;
    }
    return false;
}

bool LinkedList::Remove(const int value)
{
    //handles the case of the position being greater than the size of the linked list
    if(value - 1> size_)
    {
        return false;
    }
    Node* current_node = head_;
    int size = 0;
    while(current_node)
    {
        if(size == value - 1)
        {
            //handles the removal of the node and linking the nodes together
            Node* node_remove = current_node->next_;
            Node* new_next = node_remove->next_;
            current_node->next_ = new_next;
            delete node_remove;
            size_--;
            return true;
        }
        size++;
        current_node= current_node->next_;
    }
    return false;

}

void LinkedList::PrintValues()const 
{
    Node* current_node = head_;
    while (current_node)
    {
        //goes through the list and print the corresponding values
        std::cout << current_node->value_ << "->";
        current_node = current_node->next_;
    }
    
}

void LinkedList::PrintAddresses() const
{
    Node* current_node = head_;
    while(current_node)
    {
        //prints the addresses instead
        std::cout << &current_node << "->";
        current_node = current_node->next_;
    }
}

int LinkedList::GetValueAtPosition(const int position) const
{
    int count = 1;
    Node* current_node = head_;
    //handles the case of the position being out of bounds
    if(position < 1 || position > size_ + 1)
    {
        std::cout << "Position Error" <<std::endl;
        return 0;
    }
    while(current_node)
    {
        if(count == position)
        {
            //outputs the value
            std::cout << current_node->value_<<std::endl;
            return current_node->value_;
        }
        current_node = current_node->next_;
        count++;
    }
    return 0;
}

int LinkedList::GetSize() const
{
    //returns size in class
    return size_;
}

void LinkedList::InsertNodeAt(const int value, const int position)
{
    Node* current_node = head_;
    int location = 1;
    while (current_node)
    {
        if(location == position)
        {  
            Node* new_node = new Node(value);
            Node* new_next = current_node->next_;
            current_node->next_ = new_node;
            new_node->next_ = new_next;
            size_++;
        }
        location++;
        current_node = current_node->next_;
    }
    
}

LinkedList* LinkedList::ReverseList()
{
    LinkedList* new_list = new LinkedList();
    Node* current_node = head_;
    while(current_node)
    {
        //goes through the list and adds evey list value to the front so the last value in the original list is in the front 
        new_list->InsertNodeAtFront(current_node->value_);
        current_node = current_node->next_;
    }
    return new_list;
}

LinkedList* LinkedList::MergeIntertwine(const LinkedList& second_list)
{
    LinkedList* new_list = new LinkedList();
    Node* current_node = head_;
    Node* second_current = second_list.head_;
    int count = 0;
    while(count <= size_ || count<= second_list.size_)
    {
        //adds the node in the first list then the second list
        if(count <= size_)
        {
            new_list->InsertNode(current_node->value_);
        }
        if(count <= second_list.size_)
        {
            new_list->InsertNode(second_current->value_);
        }
        count++;
    }
    return new_list;
}

LinkedList:: ~LinkedList() 
{
    Node* node_target;
    while(head_)
    {
        //destructor
        node_target = head_;
        head_ = head_->next_;
        delete node_target;
    }
}

int main()
{
    //This is where the functions will be called.
    LinkedList my_list;
    my_list.InsertNode(10);
    my_list.InsertNode(20);
    my_list.PrintValues();
    my_list.~LinkedList();
    return 0;
}