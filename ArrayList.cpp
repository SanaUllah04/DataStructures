#include <iostream>
using namespace std;

class ArrayList
{
    int *array, *temp, *t1, *tail;
    int size, length = 0;

public:
    ArrayList(int size)
    {
        array = new int[size];
        this->size = size;
        temp = array;
        tail = array;
    }

    void getvalue()
    {
        if(length < size)
        {
            cout << "Enter value: ";
            cin >> *(temp);
            temp++;
            length++;
            tail++;
        }
        else
        {
            cout << "Array already full\n";
        }
    }

    void get_all_values()
    {
        while(length < size)
        {
            getvalue();
        }
    }

    void Insert_At_Top()
    {
        if(length == 0)
        {
            cout << "List is empty, please add values first.\n";
            return;
        }

        if(length == size)
        {
            cout << "Array is full, cannot insert at top.\n";
            return;
        }

        length++;
        temp = tail;

        while (temp != array)
        {
            *temp = *(temp - 1);
            temp--;
        }

        cout << "Enter value for the Top Item: ";
        cin >> *array;

        tail++;
    }

    void Delete()
    {
        if(length == 0)
        {
            cout << "List is empty.\n";
            return;
        }

        int key, counter = 0;
        display();
        cout << "Enter the value to delete: ";
        cin >> key;

        t1 = array;
        bool found = false;

        for(int i = 0; i < length; i++)
        {
            if(*(t1) == key)
            {
                found = true;
                break;
            }
            t1++;
            counter++;
        }

        if(found)
        {
            for(int i = counter; i < length - 1; i++)
            {
                *(t1) = *(t1 + 1);
                t1++;
            }
            tail--;
            length--;
            cout << "Value deleted.\n";
        }
        else
        {
            cout << "Value not found.\n";
        }
    }

    void display()
    {
        if(length == 0)
        {
            cout << "List is empty.\n";
            return;
        }

        t1 = array;
        for(int i = 0; i < length; i++)
        {
            cout << i << ". " << *(t1) << endl;
            t1++;
        }
    }
};

int main()
{
    int nummb, chose;
    cout << "Enter the size of the array: ";
    cin >> nummb;

    ArrayList object(nummb);

    do
    {
        cout << "\nMenu\n1. Add an input\n2. Add all inputs\n3. Display the array\n4. Delete\n5. Insert at top\n6. Exit\nSelect: ";
        cin >> chose;

        switch (chose)
        {
            case 1:
                object.getvalue();
                break;

            case 2:
                object.get_all_values();
                break;

            case 3:
                object.display();
                break;

            case 4:
                object.Delete();
                break;

            case 5:
                object.Insert_At_Top();
                break;

            case 6:
                break;

            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }

    } while (chose != 6);

    return 0;
}
