#include <iostream>
#include "RandomizedQueue.h"
using namespace std;

int main() {
    RandomizedQueue<string> stack;
    string item;
    while (cin >> item) {
        if (item != "-")
            stack.enqueue(item);
        else 
            cout << stack.dequeue() << " ";
    }
    cout << "(" << stack.size() << " left on stack)" << endl;
    return 0;
}
