#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack is empty, cannot pop\n";
            return -1;
        }
        int value = top->data;
        top = top->next;
        return value;
    }

    void display() const {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack elements: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    StackLinkedList stack;

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
