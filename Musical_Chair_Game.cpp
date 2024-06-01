#include <iostream>
using namespace std;

struct node {
    string player_name;
    node *next;
    node *pre;
};

class Game {
private:
    node *head;
    int count;

public:
    Game() : head(nullptr), count(0) {}

    void Add() {
        node* newNode = new node;
        cout << "\nEnter Player: ";
        cin.ignore();  // Clear the input buffer
        getline(cin, newNode->player_name);

        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->pre = head;
        } else {
            node* tail = head->pre;
            tail->next = newNode;
            newNode->pre = tail;
            newNode->next = head;
            head->pre = newNode;
        }
        count++;
    }

    void display() {
        if (head == nullptr) {
            cout << endl << "Nothing to see here";
            return;
        }

        node* temp = head;
        cout << "Player List:\n";
        for (int i = 0; i < count; i++) {
            cout << temp->player_name << "\n";
            temp = temp->next;
        }
        cout << endl;
    }

    void Play() {
        if (count >= 2) {
            int i, set = 3;
            char sel;
            node* temp = head;

            do {
                for (i = 1; i < set; i++) {
                    temp = temp->next;
                }
                
                if (count == 1) {
                    cout << "\nWinner is: " << temp->player_name << endl;
                    break;
                }

                cout << "Out: " << temp->player_name << endl;

                // Remove the player from the list
                temp->pre->next = temp->next;
                temp->next->pre = temp->pre;

                if (temp == head) {
                    head = temp->next;
                }

                node* toDelete = temp;
                temp = temp->next;
                delete toDelete;

                count--;

                cout << "\n\nPress Y to shuffle again or N to exit: ";
                cin >> sel;
            } while (sel == 'y' || sel == 'Y');
        } else {
            cout << "\nAt least 2 players are required to play the game\n";
        }
    }
};

int main() {
    Game g;
    int sel;
    do {
        cout << "\nPress 1: Add Players\n";
        cout << "Press 2: Start Game\n";
        cout << "Press 3: Display\n";
        cout << "Press 0: Exit the Game\n";
        cout << "\n\nSelect Option: ";
        cin >> sel;

        if (sel == 1) {
            g.Add();
        } else if (sel == 2) {
            g.Play();
        } else if (sel == 3) {
            g.display();
        }
    } while (sel != 0);

    return 0;
}
