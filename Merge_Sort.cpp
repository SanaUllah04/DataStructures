#include <iostream>
#include <vector>

using namespace std;

// Function to merge two sorted halves of the array
void merge(vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays to hold the two halves
    vector<int> leftHalf(n1);
    vector<int> rightHalf(n2);

    // Copy data to temporary arrays leftHalf[] and rightHalf[]
    for (int i = 0; i < n1; i++)
        leftHalf[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightHalf[j] = arr[middle + 1 + j];

    // Merge the two halves back into the original array arr[]
    int i = 0;  // Initial index of the first subarray
    int j = 0;  // Initial index of the second subarray
    int k = left;  // Initial index of the merged subarray

    while (i < n1 && j < n2) {
        if (leftHalf[i] <= rightHalf[j]) {
            arr[k] = leftHalf[i];
            i++;
        } else {
            arr[k] = rightHalf[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftHalf[], if there are any
    while (i < n1) {
        arr[k] = leftHalf[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightHalf[], if there are any
    while (j < n2) {
        arr[k] = rightHalf[j];
        j++;
        k++;
    }
}

// Function to perform merge sort on the array
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Same as (left + right) / 2, but avoids overflow
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

int main() {
    int n;

    // Input size of the array
    cout << "Enter the number of elements: ";
    cin >> n;

    // Input the array elements
    vector<int> arr(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Apply merge sort
    mergeSort(arr, 0, n - 1);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
