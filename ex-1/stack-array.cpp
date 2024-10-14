#include <iostream>
using namespace std;

class StackArray {
private:
    int arr[10];
    int top;

public:
    StackArray() {
        top = -1;
    }

    void push(int value) {
        if (top < 9) {
            arr[++top] = value;
        } else {
            cout << "Stack is full, cannot push " << value << "\n";
        }
    }

    int pop() {
        if (top >= 0) {
            return arr[top--];
        } else {
            cout << "Stack is empty, cannot pop\n";
            return -1;
        }
    }

    void display() const {
        if (top == -1) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    StackArray stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    
    cout << "Current Stack: ";
    stack.display();

    int poppedValue = stack.pop();
    if (poppedValue != -1) {
        cout << "Popped value: " << poppedValue << "\n";
    }

    cout << "Stack after popping: ";
    stack.display();

    return 0;
}
