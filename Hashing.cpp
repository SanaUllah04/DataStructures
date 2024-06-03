#include <iostream>
using namespace std;

class Hash {
    int size, *arr, rehash_flag = 0;

public:
    Hash(int size) {
        this->size = size;
        arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = -1;
        }
    }

    void Set_size(int size) {
        cout << endl << "Updating Size";
        this->size = size;
    }

    int prime(int no) {
        cout << endl << "Finding Prime Number";
        int prime_no = no;

        while (true) {
            bool isPrime = true;
            for (int i = 2; i * i <= prime_no; ++i) {
                if (prime_no % i == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
                break;

            prime_no++;
        }

        return prime_no;
    }

    void check() {
        cout << endl << "Checking";
        int counter = 0;

        for (int i = 0; i < size; i++) {
            if (arr[i] != -1) {
                counter++;
            }
        }

        double result = (70.0 / 100.0) * size;

        if (counter >= result) {
            cout << endl << "Rehashing needed";
            rehash_flag = 1;
            return;
        } else {
            cout << endl << "All good. Continue insertion";
            return;
        }
    }

    void Insertion(int value) {
        int index = Hash_ftn(value);
        while (arr[index] == value || arr[index] != -1) {
            index = (index + 1) % size;
        }
        arr[index] = value;
        check();
        if (rehash_flag == 1) {
            int new_size = prime(size * 2);  // Increase size and find next prime
            Rehash(new_size);
        }
        return;
    }

    void Rehash(int new_size) {
        cout << endl << "Rehashing";
        int *another = new int[new_size];

        for (int i = 0; i < new_size; i++) {
            another[i] = -1;
        }

        int old_size = size;
        size = new_size;

        for (int i = 0; i < old_size; i++) {
            if (arr[i] != -1) {
                int index = Hash_ftn(arr[i]);
                while (another[index] != -1) {
                    index = (index + 1) % new_size;
                }
                another[index] = arr[i];
            }
        }

        delete[] arr;
        arr = another;
        rehash_flag = 0;
    }

    int Hash_ftn(int data) {
        int result = data % size;
        return result;
    }

    void Delete(int value) {
        int index = Hash_ftn(value);
        int result = Search_for_Delete(value, index);

        if (result != -1) {
            arr[result] = -1;
            return;
        } else {
            cout << endl << "Sorry, couldn't find value";
            return;
        }
    }

    int Search_for_Delete(int value, int index) {
        while (arr[index] != value) {
            index = (index + 1) % size;

            if (arr[index] == -1) {
                return -1;
            }
        }
        return index;
    }

    void Search(int value) {
        int index = Hash_ftn(value);
        int counter = 0;

        if (arr[index] == -1) {
            cout << endl << "Value never added";
            return;
        }

        while (arr[index] != value) {
            index = (index + 1) % size;
            counter++;
            if (arr[index] == -1) {
                cout << endl << "Sorry, couldn't find! Error value -1";
                return;
            }

            if (counter == size) {
                cout << endl << "Not possible to find";
                return;
            }
        }
        cout << endl << "Found it, at index: " << index << " value: " << arr[index];
    }

    void Print() {
        for (int i = 0; i < size; i++) {
            cout << endl << "Array[" << i << "] = " << arr[i];
        }
        return;
    }

    ~Hash() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << endl << "Enter the size of Hash Table: ";
    cin >> size;
    Hash obj(size * 2);
    int choice, value;

    do {
        cout << "\n\n----- MENU -----\n";
        cout << "1. Insertion\n";
        cout << "2. Deletion\n";
        cout << "3. Search\n";
        cout << "4. Print\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            obj.Insertion(value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            obj.Delete(value);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            obj.Search(value);
            break;

        case 4:
            obj.Print();
            break;

        case 5:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 5);

    return 0;
}
