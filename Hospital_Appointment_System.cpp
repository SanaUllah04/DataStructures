#include <iostream>
#include <vector>
#include <limits>  // For numeric_limits
using namespace std;

class Patient 
{
public:
    string name;
    int urgency;

    Patient() {}

    Patient(string name, int urgency) 
    {
        this->name = name;
        this->urgency = urgency;
    }
};

class Heap {
public:
    vector<Patient> htree;

    void insert(Patient obj) 
    {
        htree.push_back(obj);
        heapifyUp(htree.size() - 1);
        cout << "Appointment added." << endl;
    }

    void del() 
    {
        if (htree.empty()) 
        {
            cout << "No appointments to delete." << endl;
            return;
        }

        swap(&htree[0], &htree[htree.size() - 1]);
        htree.pop_back();
        heapifyDown(0);
        cout << "Appointment sent to the doctor." << endl;
    }

    void updateUrgency(string patientName, int newUrgency) 
    {

        for (size_t i = 0; i < htree.size(); ++i) 
        {
            if (htree[i].name == patientName) 
            {
                htree[i].urgency = newUrgency;
                cout << "Urgency updated." << endl;
                heapifyUp(i);
                break;
            }
        }
    }

    void display() 
    {
        if (htree.empty()) 
        {
            cout << "No appointments to display." << endl;
            return;
        }

        cout << "\n\nCurrent Appointments:" << endl;
        for (int i = 0; i < htree.size(); i++) 
        {
            cout << "Name: " << htree[i].name << ", Urgency: " << htree[i].urgency << endl;
        }
    }

private:
    void swap(Patient *a, Patient *b) 
    {
        Patient temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node) 
    {
        while (node > 0) 
        {
            int parent = (node - 1) / 2;

            if (htree[node].urgency < htree[parent].urgency) 
            {
                swap(&htree[node], &htree[parent]);
                node = parent;
            } 
            
            else 
            {
                break;
            }
        }
    }

    void heapifyDown(int node) 
    {
        int leftChild, rightChild, minChild;
        while (true) {


            leftChild = 2 * node + 1;
            rightChild = 2 * node + 2;
            minChild = node;

            if (leftChild < htree.size() && htree[leftChild].urgency < htree[minChild].urgency) 
            {
                minChild = leftChild;
            }

            if (rightChild < htree.size() && htree[rightChild].urgency < htree[minChild].urgency) 
            {
                minChild = rightChild;
            }

            if (minChild != node) 
            {
                swap(&htree[node], &htree[minChild]);
                node = minChild;
            } else {
                break;
            }
        }
    }
};

int main() {
    Heap priorityQueue;
    int check;

    while (true) {
        cout << "\nMenu\n1. Insert\n2. Delete\n3. Display\n4. Update\n5. Exit\n\nSelect: ";
        cin >> check;

        switch (check) {
            case 1: {
                Patient obj;
                cout << "Enter Name: ";
                cin >> obj.name;
                cout << "Enter Urgency: ";
                cin >> obj.urgency;
                priorityQueue.insert(obj);
                break;
            }

            case 2:
                priorityQueue.del();
                break;

            case 3:
                priorityQueue.display();
                break;

            case 4: {
                    if (priorityQueue.htree.empty()) 
                    {
                        cout << "No appointments to delete." << endl;
                        break;
                    }
                string name;
                int newUrgency;
                cout << "Enter the patient's name for urgency update: ";
                cin >> name;
                cout << "Enter new urgency: ";
                cin >> newUrgency;
                priorityQueue.updateUrgency(name, newUrgency);
                break;
            }

            case 5:
                exit(0);
                break;

            default:
                cout << "Wrong Input" << endl;
                cin.clear();  // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
                break;
        }
    }

    return 0;
}
