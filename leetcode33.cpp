/** 33. Search in Rotated Sorted Array **/
#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int st = 0, ed = nums.size() - 1;

    while (st <= ed) {
        // Calculate the middle index
        int mid = st + (ed - st) / 2;

        // Check if the target is at the middle index
        if (nums[mid] == target) {
            return mid;
        }

        // Determine which side of the array is sorted
        if (nums[st] <= nums[mid]) {  // Left side is sorted
            // Check if the target lies within the sorted left half
            if (nums[st] <= target && target <= nums[mid]) {
                ed = mid - 1;  // Discard the right half
            } else {  // Target is not in the left half
                st = mid + 1;  // Discard the left half
            }
        } else {  // Right side is sorted
            // Check if the target lies within the sorted right half
            if (nums[mid] <= target && target <= nums[ed]) {
                st = mid + 1;  // Discard the left half
            } else {  // Target is not in the right half
                ed = mid - 1;  // Discard the right half
            }
        }
    }

    // Target not found
    return -1;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << "Index: " << search(arr, target) << endl;

    return 0;
}
