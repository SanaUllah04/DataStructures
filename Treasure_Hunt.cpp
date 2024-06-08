#include <iostream>
#include <string>
using namespace std;

struct node
{
    string data;
    node *next;
};

class treasure_Hunt
{
    node *head, *temp, *temp1;
    int index;
    string *arr, *top;
    int max_size, length;

public:
    treasure_Hunt()
    {
        head = NULL;
        temp = NULL;
        temp1 = NULL;
        index = 0;
        length = 0;
        arr = new string[100];
        top = arr;
    }

    void Insert(string name)
    {
        if (head == NULL)
        {
            head = new node;
            head->data = name;
            head->next = NULL;
            temp = head;
            index++;
        }
        else
        {
            temp1 = new node;
            temp1->data = name;
            temp1->next = NULL;
            temp->next = temp1;
            temp = temp1;
            index++;
        }
    }

    void Push(string name)
    {
        if (length < max_size)
        {
            *(top) = name;
            top++;
            length++;
        }
    }

    void Decrypt()
    {
        max_size = index;
        node *current = head;
        cout << endl << "Unknown Voice: Let's Find out the real msg!";

        // Moving to stack to convert
        for (int i = 0; i < max_size; i++)
        {
            Push(current->data);
            current = current->next;
        }

        // Clear the linked list
        head = nullptr;
    }

    void POP()
    {
        // Create a new linked list while popping from the stack
        head = new node;
        head->data = *(top);
        head->next = nullptr;
        temp = head;
        top--;
        length--;

        while (top >= arr)
        {
            temp1 = new node;
            temp1->data = *(top);
            temp1->next = nullptr;
            temp->next = temp1;
            temp = temp1;
            top--;
            length--;
        }
    }

    void Display_LinkList()
    {
        cout << endl << "Display LinkList: \t";
        node *current = head;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }

    ~treasure_Hunt()
    {
        while (head != NULL)
        {
            head = head->next;
            delete head;
        }

        head = NULL;
        temp = NULL;
        temp1 = NULL;
        max_size = 0;
        index = 0;
        length = 0;
    }
};

int main()
{
    string data1[6], data2[5];
    treasure_Hunt obj;

    data1[0] = "lollipop ";
    data1[1] = "forest ";
    data1[2] = "beside ";
    data1[3] = "the ";
    data1[4] = "tree ";
    data1[5] = "to ";

    data2[0] = "tower ";
    data2[1] = "old ";
    data2[2] = "the ";
    data2[3] = "behind ";
    data2[4] = "to ";
    data2[5] = "go ";

    // 1st Paper
    cout << endl << "Unknown Voice: Go on KEN & find the Treasure!\nKEN: I am on it, mysterious voice\n\n\t5 minutes later.....\nKEN: Huh! I guess I have found it!\nUnknown Voice: What did you find?\n\n\nKEN: A paper that says! = ";

    for (int i = 0; i < 6; i++)
    {
        cout << data1[i] << " ";
    }

    cout << endl << "\nUnknown voice: Let me help you understand !";

    for (int i = 0; i < 6; i++)
    {
        obj.Insert(data1[i]);
    }

    obj.Display_LinkList();
    obj.Decrypt();
    obj.POP();
    obj.Display_LinkList();
    obj.~treasure_Hunt();

    // 2nd Paper
    cout << endl << "KEN: thanks for the help! I am going to find this location\nUnknown Voice: Nice\nKEN: I have reached and found another letter\nUnknown Voice: What does this paper say\nKEN: It says! : \n\n\t";

    for (int i = 0; i < 5; i++)
    {
        cout << data2[i] << " ";
    }

    for (int i = 0; i < 5; i++)
    {
        obj.Insert(data2[i]);
    }

    obj.Display_LinkList();
    obj.Decrypt();
    obj.POP();
    obj.Display_LinkList();

    return 0;
}
