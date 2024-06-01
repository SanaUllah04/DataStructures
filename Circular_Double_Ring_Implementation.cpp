#include <iostream>
using namespace std;

struct node 
{
    int info;
    node* next, *previous;
};

class Circular_Doubly_Ring_List
{
    node* head, *tail, *current;

public:
    Circular_Doubly_Ring_List()
    {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    void Create_Nodes()
    {
        if (head == NULL)
        {
            head = new node;
            tail = head;
            cout << endl << "Enter Value for head : ";
            cin >> head->info;
            head->next = head;
            head->previous = head;
        }
        else
        {
            current = tail;
            tail = new node;
            cout << endl << "Enter Value for the new node : ";
            cin >> tail->info;
            tail->next = head;
            tail->previous = current;
            current->next = tail;
            head->previous = tail;
        }
    }

    void Display()
    {
        if (head == NULL)
        {
            cout << endl << "List is empty.";
        }
        else
        {
            current = head;
            cout << endl << "Ring List Items:";

            do
            {
                cout << endl << current->info;
                current = current->next;

            } while (current != head);
        }
    }

    ~Circular_Doubly_Ring_List()
    {
        current = head;

        while (current->next != head)
        {
            head = head->next;
            current->previous->next = head;
            current->next->previous = current->previous;
            delete current;
            current = head;
        }

        if (current->next == head || current == head)
        {
            delete current;
        }
    }
};

int main()
{
    Circular_Doubly_Ring_List object;
    int choice;

    do
    {
        cout << endl << "1. Add a node";
        cout << endl << "2. Display";
        cout << endl << "3. Exit";
        cout << endl << "Select : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            object.Create_Nodes();
            break;

        case 2:
            object.Display();
            break;

        case 3:
            break;

        default:
            cout << endl << "Invalid choice.";
            break;
        }
    } while (choice != 3);

    return 0;
}
