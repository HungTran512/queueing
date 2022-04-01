#ifndef RESIZING_ARRAY_STACK_H
#define RESIZING_ARRAY_STACK_H

#include <stdexcept>
using namespace std;

/* This class represents a last-in-first-out (LIFO) stack of generic items.  This
   implementation uses a resizing array, which doubles the underlying array
   when it is full and halves the underlying array when it is one-quarter
   full. */
template<typename Item>
class ResizingArrayStack {
public:
    // Initializes an empty stack
    ResizingArrayStack();

    // Releases memory allocated for the underlying array
    ~ResizingArrayStack();

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
    Item* items;  // array of items
    int n;          // number of elements on stack
    int capacity;   // size of the items array

    // Resize the underlying array holding the elements
    void resize(int cap);
};

template<typename Item>
ResizingArrayStack<Item>::ResizingArrayStack() {
    n = 0;
    capacity = 2;
    items = new Item[capacity];
}

template<typename Item>
ResizingArrayStack<Item>::~ResizingArrayStack() {
    delete[] items;
}

template<typename Item>
bool ResizingArrayStack<Item>::isEmpty() {
    return n == 0;
}

template<typename Item>
int ResizingArrayStack<Item>::size() {
    return n;
}

template<typename Item>
void ResizingArrayStack<Item>::resize(int cap) {
    Item* temp = new Item[cap];
    for (int i = 0; i < n; i++) {
        temp[i] = items[i];
    }
    delete[] items;
    items = temp;
    capacity = cap;
}

template<typename Item>
void ResizingArrayStack<Item>::push(Item item) {
    if (n == capacity) resize(2*capacity);  // double array length if necessary
    items[n++] = item;                      // add item
}

template<typename Item>
Item ResizingArrayStack<Item>::pop() {
    if (isEmpty()) throw runtime_error("Stack underflow");
    Item item = items[n-1];
    n--;
    // shrink size of array if necessary
    if (n > 0 && n == capacity/4) resize(capacity/2);
    return item;
}

template<typename Item>
Item ResizingArrayStack<Item>::peek() {
    if (isEmpty()) throw runtime_error("Stack underflow");
    return items[n-1];
}

#endif
