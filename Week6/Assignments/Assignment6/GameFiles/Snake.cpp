#include "Snake.h"
#include <iostream>

// TODO: Constructor
// - Build a snake with STARTING_LENGTH segments using `new`.
// - head should point to segment id 0 (or 1, your choice - just be consistent),
//   tail should point to the last segment created.
// - Set length and nextId appropriately.
Snake::Snake() {
    head_ = nullptr;
    tail_ = nullptr;
    length_ = 0;
    id_ = 0;
    // TODO: allocate STARTING_LENGTH nodes and link them together
    Regenerate(STARTING_LENGTH);
}

// TODO: Destructor
// - Walk the list and delete every remaining node.
// - If you don't do this, running under valgrind/ASan will report a leak.
Snake::~Snake() {
    // TODO
    Node* node_target;
    while(head_)
    {
        node_target = head_;
        head_ = head_->next_;
        delete node_target;
    }
}

// TODO: kill()
// - Remove up to `count` nodes from the FRONT of the list, deleting each one.
// - Handle the edge case where the snake has fewer than `count` nodes left:
//   kill all remaining nodes and stop. Do not crash.
// - Update `length` (and `tail`/`head` if the snake becomes empty!).
// - Return the number of segments ACTUALLY killed.
int Snake::Kill(int count) {
    // TODO
    if(count >= length_)
    {
        Snake::~Snake();
        int length = length_;
        length_ = 0;
        return length;
    }
    for(int i = 0;i < count;i++)
    {
        Node* delete_target = head_;
        head_ = head_->next_;
        delete delete_target;
        length_--;
    }
    return count;
}

// TODO: regenerate()
// - Append `count` new nodes to the BACK of the list using `new`.
// - Use `nextId` to assign each new node a unique, increasing id, and
//   increment `nextId` each time.
// - Update `tail` (and `head` if the snake was empty!) and `length`.
void Snake::Regenerate(int count) {
    // TODO
    if(head_ == nullptr)
    {
        head_ = new Node;
        head_->body_part_ = id_;
        id_++;
        length_++;
    }
    for(int i =0; i< count;i++)
    {   
        if(tail_ == nullptr)
        {
            tail_ = new Node;
            tail_->body_part_ =id_;
            head_->next_ = tail_; 
            id_++;
            length_++;
        }
        tail_->next_ = new Node;
        tail_->body_part_=id_;
        tail_ = tail_->next_;
        id_++;
        length_++;

    }
}

// TODO: print()
// - Walk the list from head to tail and print in the format:
//   Snake: [12] -> [13] -> [14] -> [15]
// - If the snake is empty, print something sensible like "Snake: (dead)".
// - This function must not modify the snake - use a `const Node*` to walk it.
void Snake::PrintSnake() const {
    // TODO
    Node* current_node = head_;
    while(current_node)
    {
        std::cout << "[" << current_node->body_part_ << "]";
        current_node = current_node->next_;
    }
}

int Snake::GetLength() const {
    // TODO
    int length = length_;
    return length;
}
