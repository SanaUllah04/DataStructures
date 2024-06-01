#include <iostream>
using namespace std;

struct node {
    node* next;
    int value;
};

class LINKLIST {
    node* head;
    int counter = 0;

public:
    LINKLIST() : head(NULL) {}

    void Create() {
        node* newNode = new node;
        cout << endl << "Enter the value: ";
        cin >> newNode->value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        counter++;
    }

    void Display() {
        if (head == NULL) {
            cout << endl << "List is empty.";
            return;
        }

        node* temp = head;
        while (temp != NULL) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void Delete() {
        if (head == NULL) {
            cout << endl << "List is empty.";
            return;
        }

        int key;
        cout << endl << "Enter value to delete: ";
        cin >> key;

        node* temp = head;
        node* previous = NULL;

        while (temp != NULL && temp->value != key) {
            previous = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Value not found." << endl;
            return;
        }

        if (previous == NULL) {
            head = head->next;
        } else {
            previous->next = temp->next;
        }

        delete temp;
        counter--;
        cout << "Value deleted." << endl;
    }
};

int main() {
    LINKLIST list;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a node\n";
        cout << "2. Display the list\n";
        cout << "3. Delete a node\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.Create();
                break;
            case 2:
                list.Display();
                break;
            case 3:
                list.Delete();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
