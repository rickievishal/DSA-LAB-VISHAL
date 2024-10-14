#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(int v)
    {
        Node *newNode = new Node();
        newNode->data = v;
        newNode->next = NULL;
        newNode->prev = tail;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "THE END!" << endl;
    }

    void deleteNodeAtBegin()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteAtEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }

    void insertAtBegin(int v)
    {
        Node *newNode = new Node();
        newNode->data = v;
        newNode->prev = NULL;
        newNode->next = head;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtPosition(int v, int p)
    {
        if (p == 0)
        {
            insertAtBegin(v);
            return;
        }

        Node *newNode = new Node();
        newNode->data = v;

        Node *temp = head;
        for (int i = 0; temp != NULL && i < p - 1; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;

        if (newNode->next == NULL)
        {
            tail = newNode;
        }
    }

    void deleteAtPosition(int p)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        if (p == 0)
        {
            deleteNodeAtBegin();
            return;
        }

        Node *temp = head;
        for (int i = 0; temp != NULL && i < p; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Position out of range." << endl;
            return;
        }

        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        if (temp == tail)
        {
            tail = temp->prev;
        }
        delete temp;
    }
};

int main()
{
    DoublyLinkedList list;
    int choice, value, position;

    do
    {
        cout << "Menu:\n";
        cout << "1. Insert at end\n";
        cout << "2. Insert at beginning\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete at beginning\n";
        cout << "5. Delete at end\n";
        cout << "6. Delete at position\n";
        cout << "7. Print list\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at end: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 2:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            list.insertAtBegin(value);
            break;
        case 3:
            cout << "Enter value and position to insert: ";
            cin >> value >> position;
            list.insertAtPosition(value, position);
            break;
        case 4:
            list.deleteNodeAtBegin();
            break;
        case 5:
            list.deleteAtEnd();
            break;
        case 6:
            cout << "Enter position to delete: ";
            cin >> position;
            list.deleteAtPosition(position);
            break;
        case 7:
            list.print();
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
