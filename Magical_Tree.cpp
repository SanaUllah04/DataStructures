#include <iostream>
using namespace std;

struct node
{
    string Jem_name;
    int Jem_energy;
    node *left, *right;

    node()
    {
        Jem_energy = 0;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
public:
    node *root;

    Tree()
    {
        root = NULL;
    }

    node* insert(node *root, const string& name, int key)
    {
        if (root == NULL)
        {
            node *newNode = new node;
            newNode->Jem_name = name;
            newNode->Jem_energy = key;
            return newNode;
        }
        else if (key < root->Jem_energy)
        {
            root->left = insert(root->left, name, key);
        }
        else if (key > root->Jem_energy)
        {
            root->right = insert(root->right, name, key);
        }

        return root;
    }

    void In_Traversing(node *temp)
    {
        if (temp == NULL)
        {
            cout << endl << "Tree doesn't exist";
            return;
        }

        if (temp->left != NULL)
        {
            In_Traversing(temp->left);
        }

        cout << temp->Jem_name << " = " << temp->Jem_energy << endl;

        if (temp->right != NULL)
        {
            In_Traversing(temp->right);
        }
    }

    node *Searching_Jem(node *current, int value)
    {
        if (current == NULL)
        {
            return NULL;
        }

        if (value == current->Jem_energy)
        {
            return current;
        }
        else if (value < current->Jem_energy)
        {
            return Searching_Jem(current->left, value);
        }
        else if (value > current->Jem_energy)
        {
            return Searching_Jem(current->right, value);
        }
    }

    void FindHighestPowerGem(node* root)
    {
        if (root == NULL)
        {
            cout << "No Tree exist";
            return;
        }

        while (root->right != NULL)
        {
            root = root->right;
        }

        cout << endl << "\tHighest Power Jem: " << root->Jem_energy << " = " << root->Jem_name;
    }
};

int main()
{
    Tree forest;

    forest.root = forest.insert(forest.root, "Ruby", 30);
    forest.root = forest.insert(forest.root, "Sapphire", 70);
    forest.root = forest.insert(forest.root, "Pearl", 40);
    forest.root = forest.insert(forest.root, "Opal", 10);
    forest.root = forest.insert(forest.root, "Garnet", 60);
    forest.root = forest.insert(forest.root, "Zircon", 20);
    forest.root = forest.insert(forest.root, "Jade", 5);

    cout << endl << "Root : " << forest.root->Jem_energy << "\tName : " << forest.root->Jem_name;
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Display the magical tree\n";
        cout << "2. Search for a gem by specifying its power\n";
        cout << "3. Find the gem with the highest magical power\n";
        cout << "4. Pluck (remove) a gem from the BST and put it in your bag\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int select;
            cout << endl << "Which Traversal do you want ?\n1. Pre-Order\n2. In-Order\n3. Post-Order\n\nSelect : "; cin >> select;
            switch (select)
            {
            case 1:
                forest.In_Traversing(forest.root);
                break;

            case 2:
                forest.In_Traversing(forest.root);
                break;

            case 3:
                forest.In_Traversing(forest.root);
                break;

            default:
                cout << endl << "Wrong Input!";
                break;
            }
            break;

        case 2:
            int value;
            node *check;
            cout << endl << "Enter the Jem to search : ";
            cin >> value;
            check = forest.Searching_Jem(forest.root, value);
            if (check != NULL)
            {
                cout << endl << check->Jem_energy << " Found it!";
            }
            else
            {
                cout << endl << "Couldn't Found!";
            }
            break;

        case 3:
            forest.FindHighestPowerGem(forest.root);
            break;

        case 4:
            cout << "Not implemented yet!";
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
