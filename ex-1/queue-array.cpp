#include <iostream>
using namespace std;

class QueueArray {
private:
    int arr[10];
    int front;
    int rear;

public:
    QueueArray() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear < 9) {
            if (front == -1) {
                front = 0;
            }
            arr[++rear] = value;
        } else {
            cout << "Queue is full, cannot enqueue " << value << "\n";
        }
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty, cannot dequeue\n";
            return -1;
        }
        return arr[front++];
    }

    void display() const {
        if (front == -1 || front > rear) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    QueueArray queue;

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
