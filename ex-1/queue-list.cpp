#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class QueueLinkedList {
private:
    Node* front;
    Node* rear;

public:
    QueueLinkedList() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty, cannot dequeue\n";
            return -1;
        }
        int value = front->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        return value;
    }

    void display() const {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    QueueLinkedList queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    
    cout << "Current Queue: ";
    queue.display();

    int dequeuedValue = queue.dequeue();
    if (dequeuedValue != -1) {
        cout << "Dequeued value: " << dequeuedValue << "\n";
    }

    cout << "Queue after dequeuing: ";
    queue.display();

    return 0;
}
