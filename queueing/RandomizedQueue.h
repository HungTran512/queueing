#ifndef RANDOMIZEDQUEUE_H
#define RANDOMIZEDQUEUE_H

#include <stdexcept>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
using namespace std;

template<typename Item>
class RandomizedQueue {
public:
   RandomizedQueue();                       // construct an empty randomized queue
   ~RandomizedQueue();                      // destructor
   bool isEmpty();                          // is the queue empty?
   int size();                              // return the number of items on the queue
   void enqueue(Item item);                 // add the item
   Item dequeue();                          // remove and return a random item
   Item sample();                           // return a random item (but do not remove it)
private:
  Item* items;
  int n;
  int cap;
  void resize(int New_cap);
};
// construct an empty randomized queue
template<typename Item>
RandomizedQueue<Item>::RandomizedQueue() {
    srand(time(0));
    n = 0;
    cap = 2;
    items = new Item[cap];
}
// destructor
template<typename Item>
RandomizedQueue<Item>::~RandomizedQueue() {
  delete[] items;
}
// check if the queue is empty
template<typename Item>
bool RandomizedQueue<Item>::isEmpty() {
  return n == 0;
}
// return the number of item you currently have in the queue
template<typename Item>
int RandomizedQueue<Item>::size() {
  return n;
}
//add an item at the back of the queue
template<typename Item>
void RandomizedQueue<Item>::enqueue(Item item){
  if (n == cap) resize(2*cap);
  items[n] = item;
  n++;
}
//remove and return a random item by exchanging the last item with the randome item, then continue to dequeue
template<typename Item>
Item RandomizedQueue<Item>::dequeue(){
  if (isEmpty()) throw runtime_error("Stack underflow");
  int x = rand() % n;
  Item temp = items[x];
  items[x] = items[n-1];
  items[n-1] = temp;
  Item item = items[n-1];
  n--;
  if (n > 0 && n == cap/4) resize(cap/2);
  return item;

}
// return a random item but not remove it
template<typename Item>
Item RandomizedQueue<Item>::sample(){
  if (n != 0){
    int x;
    x = rand() % n;
    return items[x];
  }
}
// private function that help with array resizing.
template<typename Item>
void RandomizedQueue<Item>::resize(int New_cap){
  Item* temp = new Item[New_cap];
  for (int i = 0; i < n; i++) {
      temp[i] = items[i];
  }
  delete[] items;
  items = temp;
  cap = New_cap;
}

#endif
