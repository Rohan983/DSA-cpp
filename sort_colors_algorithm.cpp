/* 
   LeetCode 75: Sort Colors 
   Problem Description:
   Given an array with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
   We will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Helper function to print the array
void printArr(vector<int> arr) {
    for (int ele : arr) {
        cout << ele << " ";
    }
    cout << endl;
    return;
}

// Unoptimized sorting method for colors, left here for educational purposes
void sortColors(vector<int>& nums) {
    int n = nums.size();
    int sz = 0, st = n-1;
    for(int i=0; i<n/2; i++){
        if(nums[i] == 0){
            swap(nums[i], nums[sz]);
            sz++;
        } else if (nums[i] == 2) {
            swap(nums[i], nums[st]);
            st--;
        }
    }
    return;
}

// Implementation of the Dutch National Flag algorithm to sort the colors
void sortColorsDNF(vector<int>& nums){
    int low = 0, mid = 0, high = nums.size()-1;

    while(mid<=high){
        if(nums[mid]<1){ // If the element is 0
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid]>1) { // If the element is 2
            swap(nums[mid], nums[high]);
            high--;
        } else { // If the element is 1
            mid++;
        }
    }
    return;
}

int main(){
    vector<int> arr = {2,0,2,1,1,0}; 

    cout << "Original array: ";
    printArr(arr);
    
    // Sorting the array using the Dutch National Flag algorithm
    sortColorsDNF(arr);
    
    cout << "Sorted array: ";
    printArr(arr);
    return 0;
}

/* 
   Explanation:
   This code implements the Dutch National Flag algorithm to sort an array of colors represented by 0, 1, and 2.
   The function `sortColorsDNF` sorts the input array in one pass with O(n) time complexity and O(1) space complexity.
   The unoptimized sorting function `sortColors` is left in the code for reference and learning purposes, showing a non-optimal approach.
*/
