#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

class LList
{
private:
    Node *head;
    Node *tail;

public:
    LList()
    {
        head = NULL;
        tail = NULL;
    }

    ~LList()
    {
        while (head != NULL)
        {
            deleteNodeAtBegin();
        }
    }

    void insertAtEnd(int v)
    {
        Node *a = new Node();
        a->data = v;
        a->link = NULL;

        if (head == NULL)
        {
            head = a;
            tail = a;
        }
        else
        {
            tail->link = a;
            tail = a;
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
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
        head = head->link;
        if (head == NULL)
        {
            tail = NULL;
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
        Node *temp = head;
        while (temp->link != tail)
        {
            temp = temp->link;
        }
        delete tail;
        tail = temp;
        tail->link = NULL;
    }

    void insertAtBegin(int v)
    {
        Node *a = new Node();
        a->data = v;
        a->link = head;
        head = a;
        if (tail == NULL)
        {
            tail = a;
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
            temp = temp->link;
        }

        if (temp == NULL)
        {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }

        newNode->link = temp->link;
        temp->link = newNode;
        if (newNode->link == NULL)
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
        Node *prev = NULL;
        for (int i = 0; temp != NULL && i < p; i++)
        {
            prev = temp;
            temp = temp->link;
        }

        if (temp == NULL)
        {
            cout << "Position out of range." << endl;
            return;
        }

        prev->link = temp->link;
        if (temp->link == NULL)
        {
            tail = prev;
        }
        delete temp;
    }
};

int main()
{
    LList list;
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
