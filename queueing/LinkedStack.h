#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <stdexcept>
using namespace std;

/* This class represents a last-in-first-out (LIFO) stack of generic items.
   This implementation uses a singly linked list. */
template<typename Item>
class LinkedStack {
public:
    // Initializes an empty stack
    LinkedStack();

    // Releases memory allocated for the nodes in the list
    ~LinkedStack();

    // Returns true if this stack is empty; false otherwise
    bool isEmpty();

    // Returns the number of items in the stack
    int size();

    // Adds the item to this stack
    void push(Item item);

    /* Removes and returns the item most recently added to this stack.  Throws
       an exception if this stack is empty. */
    Item pop();

    /* Returns (but does not remove) the item most recently added to this
       stack.  Throws an exception if this stack is empty. */
    Item peek();

private:
    struct Node {
        Item item;
        Node* next;
    };
    int n;           // number of elements on stack
    Node* first;     // top of the stack
};

template<typename Item>
LinkedStack<Item>::LinkedStack() {
    first = nullptr;
    n = 0;
}

template<typename Item>
LinkedStack<Item>::~LinkedStack() {
    Node *curr = first;
    Node *before = nullptr;
    while (curr != nullptr) {
        before = curr->next;
        delete curr;
        curr = before;
    }
}

template<typename Item>
bool LinkedStack<Item>::isEmpty() {
    return n == 0;
}

template<typename Item>
int LinkedStack<Item>::size() {
    return n;
}

template<typename Item>
void LinkedStack<Item>::push(Item item) {
    Node* oldfirst = first;
    first = new Node;
    first->item = item;
    first->next = oldfirst;
    n++;
}

template<typename Item>
Item LinkedStack<Item>::pop() {
    if (isEmpty()) throw runtime_error("Stack underflow");
    Item item = first->item;    // save item to return
    Node* oldfirst = first;
    first = first->next;        // delete first node
    delete oldfirst;
    n--;
    return item;                // return the saved item
}

template<typename Item>
Item LinkedStack<Item>::peek() {
    if (isEmpty()) throw runtime_error("Stack underflow");
    return first->item;
}

#endif
