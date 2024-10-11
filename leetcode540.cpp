/** 540. Single Element in a Sorted Array **/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Function to find the single non-duplicate element in a sorted array
int singleNonDuplicate(vector<int>& nums) {
    int st = 0, ed = nums.size(); // Initialize start and end pointers

    // Perform binary search to find the single non-duplicate element
    while (st <= ed) {
        int mid = st + (ed - st) / 2; // Calculate middle index

        // Check boundary conditions for the first or last element
        if (mid == 0 || mid == nums.size()) return nums[mid];

        // If the middle element is the single non-duplicate (doesn't match its neighbors)
        if (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid]) {
            return nums[mid];
        }

        // Check if mid is even
        if (mid % 2 == 0) {
            // If the element at mid equals the one before it, search in the left half
            if (nums[mid] == nums[mid - 1]) {   
                ed = mid - 1;
            } 
            // Else, search in the right half
            else {
                st = mid + 1;
            }
        } 
        // If mid is odd
        else {
            // If the element at mid equals the one before it, search in the right half
            if (nums[mid] == nums[mid - 1]) {
                st = mid + 1;
            } 
            // Else, search in the left half
            else {
                ed = mid - 1;
            }
        }
    }

    // Return -1 if no single element is found (though this shouldn't happen)
    return -1;
}

int main() {
    // Test case 1: Array with a single non-duplicate element
    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "1. Single Element is: " << singleNonDuplicate(nums1) << endl;

    // Test case 2: Another array with a single non-duplicate element
    vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    cout << "2. Single Element is: " << singleNonDuplicate(nums2) << endl;

    return 0;
}
