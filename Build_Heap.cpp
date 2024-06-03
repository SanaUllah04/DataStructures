#include <iostream>
#include <queue>
using namespace std;

struct node {
    node* left, *right;
    int info;

    node(int val) : info(val), left(NULL), right(NULL) {}
};

class Heap {
    public:
        node *root;

        Heap() : root(NULL) {}

        void Insert(int value) {
            if (root == NULL) {
                root = new node(value);
                return;
            }

            // Use a queue to perform level-order insertion
            queue<node*> q;
            q.push(root);

            while (!q.empty()) {
                node* current = q.front();
                q.pop();

                if (current->left == NULL) {
                    current->left = new node(value);
                    break;
                } else {
                    q.push(current->left);
                }

                if (current->right == NULL) {
                    current->right = new node(value);
                    break;
                } else {
                    q.push(current->right);
                }
            }
        }

        void printLevelOrder() {
            if (root == NULL) {
                cout << "Heap is empty." << endl;
                return;
            }

            queue<node*> q;
            q.push(root);

            while (!q.empty()) {
                node* current = q.front();
                q.pop();

                cout << current->info << " ";

                if (current->left != NULL) {
                    q.push(current->left);
                }

                if (current->right != NULL) {
                    q.push(current->right);
                }
            }
            cout << endl;
        }
};

void printMenu() {
    cout << "Menu:" << endl;
    cout << "1. Insert into Heap" << endl;
    cout << "2. Print Heap Level Order" << endl;
    cout << "3. Exit" << endl;
}

int main() {
    Heap heap;
    int choice, value;

    while (true) {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                heap.Insert(value);
                break;
            case 2:
                heap.printLevelOrder();
                break;
            case 3:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
