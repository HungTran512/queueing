#ifndef DEQUE_H
#define DEQUE_H
#include <stdexcept>
using namespace std;

template<typename Item>
class Deque {
public:
  Deque();                                 // construct an empty deque
  ~Deque();                                // destructor
  bool isEmpty();                          // is the deque empty?
  int size();                              // return the number of items on the deque
  void addFirst(Item item);                // add the item to the front
  void addLast(Item item);                 // add the item to the end
  Item removeFirst();                      // remove and return the item from the front
  Item removeLast();                       // remove and return the item from the end
private:
  struct Node {
      Item item;
      Node* next;
      Node* previous;
  };
  int n;
  Node* head;
  Node* tail;
};
// Constructor
template<typename Item>
Deque<Item>::Deque(){
  head = nullptr;
  tail = nullptr;
  n = 0;
}
//destructor
template<typename Item>
Deque<Item>::~Deque() {
    Node *curr = head;
    Node *previous = nullptr;
    while (curr != nullptr) {
        previous = curr->next;
        delete curr;
        curr = previous;
    }
}
// check if the deck is empty
template<typename Item>
bool Deque<Item>::isEmpty(){
  return n == 0;
}
// return deck size
template<typename Item>
int Deque<Item>::size(){
  return n;
}
//add an element to the front of the deck
template<typename Item>
void Deque<Item>::addFirst(Item item){
  Node* to_add = new Node;
  to_add->item = item;
  to_add->next = head;
  if(head != nullptr){
    head -> previous = to_add;
  }
  else{
    tail = to_add;
  }
  to_add ->previous = nullptr;
  head = to_add;
  n++;
}
//add an element to the back of the deck
template<typename Item>
void Deque<Item>::addLast(Item item){
  Node* to_add = new Node;
  to_add->item = item;
  to_add->previous = tail;
  if(tail != nullptr){
    tail -> next = to_add;
  }
  else{
    head = to_add;
  }
  to_add ->next = nullptr;
  tail = to_add;
  n++;
}
//remove an element at the front of the deck
template<typename Item>
Item Deque<Item>::removeFirst(){
  if (isEmpty()) throw runtime_error("Stack underflow");

  Item item = head -> item;
  Node* to_remove = head;
  head = head -> next;
  delete to_remove;
  n--;
  return item;
}
//add an element at the back of the deck
template<typename Item>
Item Deque<Item>::removeLast(){
  if (isEmpty()) throw runtime_error("Stack underflow");

  Item item = tail -> item;
  Node* to_remove = tail;
  tail = tail -> previous;
  delete to_remove;
  n--;
  return item;
}

#endif
