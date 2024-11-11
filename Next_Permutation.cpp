/* 
   LeetCode 31: Next Permutation 
   Problem Description:
   Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
   If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
   The replacement must be in place and use only constant extra memory.
*/

#include<iostream>
#include<vector>
using namespace std;

// Helper function to print the array
void printArr(vector<int> arr) {
    for (int ele : arr) {
        cout << ele << " ";
    }
    cout << endl;
    return;
}

// Function to find the next lexicographical permutation of the given vector (LeetCode 31)
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return;
    
    int pivot = -1;
    // Find the rightmost element which is smaller than its next element
    for(int i = n - 2; i >= 0; i--) {
        if(nums[i] < nums[i + 1]) {
            pivot = i;
            break; 
        }
    }
    
    // If there is a pivot, find the rightmost element that is greater than the pivot and swap
    if(pivot != -1) {
        for(int i = n - 1; i > pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }
    }
    
    // Reverse the sequence after the pivot to get the next smallest lexicographical order
    int left = pivot + 1, right = n - 1;
    while(left <= right) {
        swap(nums[left++], nums[right--]);
    }
    return;
}

int main() {
    vector<int> nums = {1, 1, 5};

    cout << "Present Permutation: ";
    printArr(nums);
    nextPermutation(nums);
    cout << "Next Permutation: ";
    printArr(nums);

    return 0;
}
