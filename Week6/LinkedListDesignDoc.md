# Project3 DesignDocument

## Program Name

Project3.cpp & Project3.h

## Purpose

Briefly explain what the program does and what problem it solves.

Project3.h handles instantiation of key elements in the program, such as the node struct, 
the LinkedList class with all function declarations, and private values that can be modified in functions.

Project3.cpp contains the definitons for all the functions declared in Project3.h, as well as a main function.

---

## Inputs

List all inputs the program will receive.

Example:

int value  the value is used to determine the value of the inserted node
int position the position is used to determine the location in which an action occurs.
---

## Outputs

List what the program will display or produce.

-LinkedList and their values or memory, depending on the function called.
---

## Variables

int position  location where called action will occur
int value value assigned to created node.

LinkedList* A secondary linked list that can be used.

---

## Key Design Choices

Explain any important decisions you made when designing the program.

I used specific nodes so that the insertion and removal of nodes is simplified
---

## Program Steps (Algorithm)
Initialize a linked list
Call functions based on the actions requested.
modify the list depending on the functions called.
Output certain information based on the functions called.
Use a destructor to delete nodes.
---

## Functions

~LinkedList() destructor for the linked List
LinkedList() constructor for the linked list.
void InsertNode(const int value) inserts the node at the back of the list with a time complexity of O(1) ,
 since the address for the end is already present.
void InsertNodeAtFront(const int value); Inserts the node at the front of the list with a time complexity of O(1), 
 since the address for the head is already present and no searching is neede
bool Contains(const int value) const; Searches the list with a time complexity of O(n) to find if the list contains the value inputted
 and returns true if it finds it and false otherwise.
bool Remove(const int position); Removes the node at a specific position with a time complexity of O(n)
 since it will have to search the list for the position.
void PrintValues() const; Goes through the list at a complexity of O(n) and outputs the values. 
void PrintAddresses() const; Goes through the list at a complexity of O(n) and outputs the memory addresses.
int GetValueAtPosition(const int position) const; Looks through the list with a complexity of O(n) and gets the value at the position inputted
void InsertNodeAt(const int value, const int position); Searches the list with a complexity of O(n) and inserts a new node with the inputted value
 at the inputted position
int GetSize() const; returns the size variable
LinkedList* ReverseList(); creates a new linkedlist and searches the new list with a complexity of O(n) and inputs the original list
 nodes into the new list in reversed order  
LinkedList* MergeIntertwine(const LinkedList& second_list); Merges two linked list together, which has a time complexity of O(n), with n being the size of the greater list. 
    
---

## Sample Input/Output

Input:
LinkedList my_list
my_list.InsertNode(10);
my_list.PrintValues();
my_list.~LinkedList();
Output:
10 ->
---

## Testing

### Test Case 1
Input:
LinkedList my_list;
my_list.InsertNode(10);
my_list.InsertNode(20);
my_list.PrintValues();
my_list.~LinkedList();
return 0;



Output:
10->10->20->
