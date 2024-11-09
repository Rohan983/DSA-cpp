/* 
   LeetCode 88: Merge Sorted Array 
   Problem Description:
   You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
   Merge nums2 into nums1 as one sorted array in-place.
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Helper function to print the array
void printArr(vector<int> arr) {
    // Print each element in the vector and add a space between elements
    for (int ele : arr) {
        cout << ele << " ";
    }
    cout << endl;
    return;
}

// Function to merge two sorted arrays (nums1 and nums2) into nums1 in-place (LeetCode 88)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // Start merging nums1 and nums2 from the back to utilize empty slots in nums1 effectively
    // If nums2 is empty, there's nothing to merge, return
    if(n == 0) return;
    
    // If nums1 is empty (only has zeros), replace nums1 with nums2
    if(m == 0) {
        nums1 = nums2;
        return;
    }
    
    // Initialize the position from the end of the combined size of nums1 and nums2
    int pos = m + n - 1;
    // Set initial position for merging from the end of nums1
    m--;  // Adjust m and n to point to the last valid elements in each array
    n--;
    
    // Merge elements from the end of each array towards the beginning
    while(m >= 0 && n >= 0){
        // Compare the last elements of nums1 and nums2, and place the larger one at the current position
        // Place the larger element at the current position in nums1
        if(nums1[m] >= nums2[n]){
            nums1[pos--] = nums1[m--];
        } else {
            nums1[pos--] = nums2[n--];
        }
    }

    // If any elements are left in nums2, fill them into nums1
    while(n >= 0){
        // If any elements from nums2 are still remaining, place them in nums1
        nums1[pos--] = nums2[n--];
    }
    return;
}

int main() {
    vector<int> nums1 = {4, 5, 6, 0, 0, 0};  // nums1 has extra space for merging
    vector<int> nums2 = {1, 2, 3};           // nums2 contains the sorted array to merge
    int m = 3, n = 3;                         // Length of the sorted parts of nums1 and nums2

    // Print the arrays before merging
    cout << "Before merge:" << endl;
    printArr(nums1);
    printArr(nums2);

    // Merge nums2 into nums1
    merge(nums1, m, nums2, n);

    // Print the merged array
    cout << "After merge: " << endl;
    printArr(nums1);

    return 0;
}
