/** 852. Peak Index in a Mountain Array **/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Function to find the peak index in a mountain array
int peakIndexInMountainArray(vector<int>& arr) {
    // Initialize the start (st) and end (ed) pointers
    int st = 0, ed = arr.size() - 1;

    // Perform binary search to find the peak element
    while (st <= ed) {
        // Calculate the middle index to avoid overflow
        int mid = st + (ed - st) / 2;

        // If the middle element is the first element
        // Return the last index since the peak can't be at the start
        if (mid == 0) {
            return ed;
        }

        // If the middle element is the last element
        // Return the first index since the peak can't be at the end
        if (mid == arr.size() - 1) {
            return st;
        }

        // Check if the middle element is the peak (greater than both neighbors)
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            return mid; // Found the peak, return the index
        }

        // If the middle element is increasing (left side of the peak),
        // move the start pointer to the right
        if (arr[mid - 1] < arr[mid]) {
            st = mid + 1;
        } 
        // If the middle element is decreasing (right side of the peak),
        // move the end pointer to the left
        else {
            ed = mid - 1;
        }
    }

    // Return -1 if no peak is found (though this shouldn't happen in a valid mountain array)
    return -1;
}

int main() {
    // Example mountain array
    vector<int> arr = {24, 69, 100, 99, 79, 78, 67, 36, 26, 19};

    // Output the index of the peak element
    cout << peakIndexInMountainArray(arr) << endl;

    return 0;
}
