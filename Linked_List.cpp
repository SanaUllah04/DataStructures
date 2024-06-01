#include <iostream>
using namespace std;

class node
{
    string item;
    node *ptr;
    static int count;

public:
    node() : ptr(NULL) 
    {
        count++;
    }

    void Take_Data(string info, node *p)
    {
        item = info;
        ptr = p;
    }

    string Get_INFO()
    {
        return item;
    }

    node* Get_address()
    {
        return ptr;
    }

    static void Display(node *p)
    {
        while(p != NULL)
        {
            cout << "Value : " << p->Get_INFO() << endl;
            p = p->Get_address();
        }
        cout << "Total Node count: " << count << endl;
    }

    // Function to make a node at the end.
    void Create_another_Node(string name, node** address)
    {
        node* NEW = new node;
        NEW->Take_Data(name, NULL);

        if(*address == NULL)
        {
            *address = NEW;
        }
        else
        {
            node* Last = *address;
            while(Last->ptr != NULL)
            {
                Last = Last->Get_address();
            }
            Last->ptr = NEW;
        }
    }

    // Function to make a node in front of the LL.
    void ADDNode_atFront(node** head, string name)
    {
        node* first = new node;
        first->Take_Data(name, *head);
        *head = first;
    }

    ~node()
    {
        count--;
    }
};

int node::count = 0;

int main()
{
    node* head = NULL;
    int choice;
    string name;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a node at the front\n";
        cout << "2. Add a node at the end\n";
        cout << "3. Display the list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To consume the newline character left in the input buffer

        switch(choice) {
            case 1:
                cout << "Enter the name to add at front: ";
                getline(cin, name);
                if (head == NULL) {
                    head = new node;
                    head->Take_Data(name, NULL);
                } else {
                    head->ADDNode_atFront(&head, name);
                }
                break;
            case 2:
                cout << "Enter the name to add at end: ";
                getline(cin, name);
                if (head == NULL) {
                    head = new node;
                    head->Take_Data(name, NULL);
                } else {
                    head->Create_another_Node(name, &head);
                }
                break;
            case 3:
                node::Display(head);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 4);

    // Deallocate nodes to prevent memory leaks
    node* current = head;
    while(current != NULL)
    {
        node* next = current->Get_address();
        delete current;
        current = next;
    }

    return 0;
}
