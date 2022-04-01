#include <iostream>
#include "Deque.h"
using namespace std;

int main() {
    Deque<string> Deque;
    string item;
    while (cin >> item) {
        if (item != "-" && item != "x" && item != "l"){
            Deque.addFirst(item);
            cout << "add first" << endl;
          }
        else if (item == "x"){
            Deque.addLast(item);
            cout << "add last" << endl;
          }
        else if (item == "-"){
            Deque.removeFirst();
            cout << "remove first" << endl;
            cout << "(" << Deque.size() << " left on Deque)" << endl;
            if (!Deque.isEmpty()){
              cout << "not empty" << endl;
            }
        }
        else if (item == "l"){
           Deque.removeLast();
           cout << "remove last" << endl;
           cout << "(" << Deque.size() << " left on Deque)" << endl;
           if (!Deque.isEmpty()){
             cout << "not empty" << endl;
        }
      }
    }
    cout << "(" << Deque.size() << " left on Deque)" << endl;
    return 0;
}
