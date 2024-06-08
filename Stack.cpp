#include <iostream>
using namespace std;

struct stack
{
    int number;
    stack *next;
};

class Plates
{
    int length, size = 10;
    stack* top, *temp, *head;

public:
    Plates()
    {
        head = NULL;
        top = NULL;
        length = 0;
    }

    void push()
    {
        if(length == size)
        {
            cout<<endl<<"Stack completed! Overflow";
            return;
        }

        stack* newPlate = new stack;
        cout<<endl<<"Number of plate : ";
        cin>>newPlate->number;
        newPlate->next = NULL;

        if(head == NULL)
        {
            head = newPlate;
            top = head;
        }
        else
        {
            top->next = newPlate;
            top = newPlate;
        }
        length++;
    }

    void POP()
    {
        if(length == 0)
        {
            cout<<endl<<"Underflow";
            return;
        }

        cout<<endl<<"Top Value : "<<top->number;

        if(top == head)
        {
            delete top;
            head = NULL;
            top = NULL;
        }
        else
        {
            temp = head;
            while(temp->next != top)
            {
                temp = temp->next;
            }
            delete top;
            top = temp;
            top->next = NULL;
        }
        length--;
    }

    void Display()
    {
        if(length == 0)
        {
            cout<<endl<<"List doesn't exist";
            return;
        }

        temp = head;
        while(temp != NULL)
        {
            cout<<endl<<temp->number;
            temp = temp->next;
        }
    }

    ~Plates()
    {
        while(head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        head = NULL;
        top = NULL;
        temp = NULL;
        length = 0;
    }
};

int main()
{
    Plates object;
    int select;

    do
    {
        cout<<endl<<"Menu\n1. Push\n2. POP\n3. Display\n4. Exit\n\nSelect : ";
        cin>>select;
        switch(select)
        {
            case 1:
                object.push();
                break;

            case 2:
                object.POP();
                break;

            case 3:
                object.Display();
                break;

            default:
                if (select != 4)
                    cout<<endl<<"Invalid option! Try again.";
                break;
        }

    }while(select != 4);

    cout<<endl<<"Bye Bye";
    return 0;
}
