#include "RandomizedQueue.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
  //change the number of argument into int
  int k = stoi(argv[1]);
  RandomizedQueue<string> QUEUE;
  string N;
  // taking in arguments and enqueueing
  while(cin >> N){
    QUEUE.enqueue(N);
  }
  //dequeueing
  for (int i =0; i < k; i++){
    cout << QUEUE.dequeue() << endl;
  }
  cout << endl;
}
