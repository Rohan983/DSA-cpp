/*
 * Sorting O(n^2) Algorithms:
 * 1. Bubble Sort
 * 2. Selection Sort
 * 3. Insertion Sort
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to print elements of an array
void printArr(vector<int> arr) {
    for (int ele : arr) {
        cout << ele << " ";
    }
    cout << endl;
    return;
}

// Bubble Sort Algorithm
// Time Complexity: O(n^2)
// Optimized to exit early if no swaps occur, indicating the array is already sorted
void bubbleSort(vector<int> &arr) {
    bool isSorted = true;
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        // Traverse the array from the beginning to the unsorted portion
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                swap(arr[j], arr[j + 1]);
                isSorted = false;
            }
        }
        // If no swaps happened during this pass, the array is sorted
        if (isSorted) return;
    }
    return;
}

// Selection Sort Algorithm
// Time Complexity: O(n^2)
// Finds the minimum element and places it in the correct position
void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minidx = i;
        for (int j = i; j < n; j++) {
            // Find the index of the minimum element in the unsorted portion
            if (arr[j] < arr[minidx]) {
                minidx = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted portion
        swap(arr[minidx], arr[i]);
    }
    return;
}

// Insertion Sort Algorithm
// Time Complexity: O(n^2)
// Builds the sorted array one element at a time
void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;

        // Move elements greater than 'curr' one position ahead to make space for 'curr'
        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        // Insert the current element in its correct position
        arr[prev + 1] = curr;
    }
}

int main() {
    vector<int> arr = {1, 3, 5, 2};
    cout << "Original Array: ";
    printArr(arr);

    // Uncomment the sorting algorithm you want to use
    // bubbleSort(arr);
    // selectionSort(arr);
    insertionSort(arr);

    cout << "Sorted Array: ";
    printArr(arr);

    return 0;
}
