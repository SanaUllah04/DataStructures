#include <iostream>
using namespace std;

// Thread = 1
// Child  = 0

struct node {
    node *left, *right;
    int info;
    bool LTH, RTH;

    node() {
        left = nullptr;
        right = nullptr;
        LTH = 1;
        RTH = 1;
    }
};

class Tree {
public:
    node *root, *dummy;

    Tree() {
        root = nullptr;
        dummy = new node;
        dummy->info = -1;
        dummy->right = dummy;
        dummy->RTH = 0;
        dummy->left = dummy;
        root = dummy;
    }

    void Insert(int value, node *current) {
        if (current == root && current->LTH == 1 && dummy->LTH == 1) {
            current->left = new node;
            current->left->info = value;
            current->left->left = root;
            current->left->right = root;
            dummy->LTH = 0;
            return;
        }

        if (current->info == value) {
            cout << "Duplicate exists" << endl;
            return;
        }

        if (current->info > value) {
            if (current->LTH == 0) {
                Insert(value, current->left);
            } else {
                node *temp = new node;
                temp->info = value;
                temp->left = current->left;
                temp->right = current;
                current->left = temp;
                current->LTH = 0;
            }
        } else if (current->info < value) {
            if (current->RTH == 0) {
                Insert(value, current->right);
            } else {
                node *temp = new node;
                temp->info = value;
                temp->right = current->right;
                temp->left = current;
                current->right = temp;
                current->RTH = 0;
            }
        }
    }

    void fastInorder(node* p) {
        while ((p = nextInorder(p)) != dummy) {
            cout << p->info << " ";
        }
        cout << endl;
    }

    node* nextInorder(node* T) {
        if (T->RTH == 1) {
            return T->right;
        } else {
            T = T->right;
            while (T->LTH == 0) {
                T = T->left;
            }
            return T;
        }
    }

    void Delete(int value, node *&current) {
        if (current == dummy || current == nullptr) {
            cout << "Node not found" << endl;
            return;
        }

        if (value < current->info) {
            Delete(value, current->left);
        } else if (value > current->info) {
            Delete(value, current->right);
        } else {
            if (current->LTH == 1 && current->RTH == 1) {
                delete current;
                current = dummy;
            } else if (current->LTH == 1) {
                node *temp = current;
                current = current->right;
                delete temp;
            } else if (current->RTH == 1) {
                node *temp = current;
                current = current->left;
                delete temp;
            } else {
                node *inorderSuccessor = current->right;
                while (inorderSuccessor->LTH == 0) {
                    inorderSuccessor = inorderSuccessor->left;
                }
                current->info = inorderSuccessor->info;
                Delete(inorderSuccessor->info, current->right);
            }
        }
    }

    void Search(int value, node *current) {
        if (current == dummy) {
            cout << "Not Found" << endl;
            return;
        }

        if (current->info == value) {
            cout << "Found it!" << endl;
            return;
        }

        if (current->info < value) {
            Search(value, current->right);
        } else {
            Search(value, current->left);
        }
    }
};

int main() {
    Tree obj;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display In-Order\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                obj.Insert(value, obj.root);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                obj.Delete(value, obj.root);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                obj.Search(value, obj.root);
                break;

            case 4:
                cout << "In-order traversal: ";
                obj.fastInorder(obj.dummy);
                break;

            case 5:
                exit(0);

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
