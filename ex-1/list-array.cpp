#include <iostream>
using namespace std;

class ArrayList {
private:

    int arr[10];
    int size;                       

public:

    ArrayList() {
        size = 0; 
    }

    
    void insertAtEnd(int value) {
        if (size < 10) {
            arr[size] = value;
            size++;
        } else {
            cout << "List is full, cannot insert " << value << endl;
        }
    }

    
    void insertAtBegin(int value) {
        if (size < 10) {
            for (int i = size; i > 0; i--) {
                arr[i] = arr[i - 1]; 
            }
            arr[0] = value;
            size++;
        } else {
            cout << "List is full, cannot insert " << value << endl;
        }
    }

    
    int pop() {
        if (size > 0) {
            size--;
            return arr[size]; 
        } else {
            cout << "List is empty, cannot pop" << endl;
            return -1; 
        }
    }

    // Display the list
    void display() const {
        if (size == 0) {
            cout << "List is empty." << endl;
        } else {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    ArrayList list; 

    
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBegin(5);
    list.insertAtEnd(30);
    list.insertAtEnd(40); 
    list.insertAtEnd(50); 

    
    cout << "Current List: ";
    list.display();

    
    int poppedValue = list.pop();
    if (poppedValue != -1) {
        cout << "Popped value: " << poppedValue << endl;
    }


    cout << "List after popping: ";
    list.display();

    return 0;
}
