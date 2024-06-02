#include <iostream>
using namespace std;

struct node {
    node *left, *right;
    int info;

    node() {
        left = NULL;
        right = NULL;
    }
};

class Tree {
    node *temp;

public:
    node *root;

    Tree() {
        temp = NULL;
        root = NULL;
    }

    void Insert(int value, node *current) {
        if (root == NULL) {
            root = new node;
            root->info = value;
            return;
        }

        if (current->info == value) {
            cout << "Duplicate exists" << endl;
            return;
        }

        if (current->info > value) {
            if (current->left != NULL) {
                Insert(value, current->left);
            } else {
                current->left = new node;
                current->left->info = value;
                return;
            }
        } else if (current->info < value) {
            if (current->right != NULL) {
                Insert(value, current->right);
            } else {
                current->right = new node;
                current->right->info = value;
                return;
            }
        }
    }

    void InOrder_Traversal(node *current) {
        if (current == NULL) {
            return;
        }

        if (current->left != NULL) {
            InOrder_Traversal(current->left);
        }

        cout << current->info << " ";

        if (current->right != NULL) {
            InOrder_Traversal(current->right);
        }
    }

    void Search(int value, node *current) {
        if (current == NULL) {
            cout << "Value not found" << endl;
            return;
        }

        if (current->info == value) {
            cout << "Found it!" << endl;
            return;
        }

        if (current->info < value) {
            Search(value, current->right);
        } else if (current->info > value) {
            Search(value, current->left);
        }
    }

    void Delete(int value, node *&current) {
        if (current == NULL) {
            cout << "Node not found" << endl;
            return;
        }

        if (value < current->info) {
            Delete(value, current->left);
        } else if (value > current->info) {
            Delete(value, current->right);
        } else {
            if (current->left == NULL && current->right == NULL) {
                delete current;
                current = NULL;
                return;
            } else if (current->left == NULL) {
                node *temp = current;
                current = current->right;
                delete temp;
                return;
            } else if (current->right == NULL) {
                node *temp = current;
                current = current->left;
                delete temp;
                return;
            } else {
                node *another = current->right;
                while (another->left != NULL) {
                    another = another->left;
                }
                current->info = another->info;
                Delete(another->info, current->right);
            }
        }
    }
};

int main() {
    Tree tree;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert a value\n";
        cout << "2. Search for a value\n";
        cout << "3. Delete a value\n";
        cout << "4. Display the tree (InOrder)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.Insert(value, tree.root);
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                tree.Search(value, tree.root);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.Delete(value, tree.root);
                break;
            case 4:
                cout << "InOrder traversal of the tree: ";
                tree.InOrder_Traversal(tree.root);
                cout << endl;
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
