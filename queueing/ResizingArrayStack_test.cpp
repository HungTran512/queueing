#include <iostream>
#include "ResizingArrayStack.h"
using namespace std;

int main() {
    ResizingArrayStack<string> stack;
    string item;
    while (cin >> item) {
        if (item != "-")
            stack.push(item);
        else if (!stack.isEmpty())
            cout << stack.pop() << " ";
    }
    cout << "(" << stack.size() << " left on stack)" << endl;
    return 0;
}
