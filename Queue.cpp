#include <iostream>
using namespace std;

class Queue
{
    int size;
    int *queue, *head, *rear, *top;

public:
    Queue(int size)
    {
        this->size = size;
        queue = new int[size];
        head = queue;
        rear = queue;
        top = queue;
        for (int i = 0; i < size; i++)
        {
            queue[i] = -1;
        }
    }

    ~Queue()
    {
        delete[] queue;
    }

    void Enqueue(int value)
    {
        if ((rear == head && *head != -1) || (rear != head && *rear != -1))
        {
            cout << endl << "Queue Overflow";
            return;
        }

        if (*rear == -1)
        {
            *rear = value;
            rear++;
            if (rear == queue + size)
            {
                rear = queue;
            }
            cout << "\nAdded";
            return;
        }
    }

    void Dequeue()
    {
        if (top == rear && *top == -1)
        {
            cout << endl << "Queue UnderFlow";
            return;
        }

        cout << endl << "Value to Delete: " << *top;
        *top = -1;
        top++;
        if (top == queue + size)
        {
            top = queue;
        }
    }

    void Display()
    {
        int *temp = head;
        for (int i = 0; i < size; i++)
        {
            cout << i << ": " << *(temp++) << endl;
        }
    }
};

int main()
{
    // Size of array
    Queue obj(10);
    int select;

    while (true)
    {
        cout << "\n1. Enqueue\n2. Display\n3. Dequeue\n0. Exit\n\nSelect: ";
        cin >> select;
        switch (select)
        {
            case 1:
            {
                int value;
                cout << "\nEnter value : ";
                cin >> value;
                obj.Enqueue(value);
                break;
            }

            case 2:
                obj.Display();
                break;

            case 3:
                obj.Dequeue();
                break;

            case 0:
                return 0;

            default:
                cout << endl << "Wrong option";
                break;
        }
    }
}
