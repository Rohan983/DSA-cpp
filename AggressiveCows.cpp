/** Aggressive cows : SPOJ 
 * https://www.spoj.com/problems/AGGRCOW/ **/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm> // for sort()
using namespace std;

// Function to check if it is possible to place the cows such that the minimum distance between any two cows is at least maxDist
bool isValid(vector<int> &arr, int n, int c, int maxDist){
    int cows = 1; // Place the first cow at the first stall
    int pos = arr[0]; // Position of the last placed cow

    for(int i = 1; i < n; i++){
        if(arr[i] - pos >= maxDist){ // Correct condition: distance between current position and last placed cow
            cows++; // Place another cow
            pos = arr[i]; // Update the position of the last placed cow
        }

        if(cows == c) return true; // Return true if all cows are placed successfully
    }

    return false; // Return false if not all cows can be placed
}

// Function to find the largest minimum distance between the cows
int largestMinDist(vector<int> &arr, int n, int c){
    if(c > n) return -1; // If there are more cows than stalls, return -1

    sort(arr.begin(), arr.end()); // Ensure stall locations are sorted

    int st = 1, ed = arr[n-1] - arr[0], ans = -1; // Start with distance range from 1 to (maximum - minimum)

    while(st <= ed){
        int mid = st + (ed - st) / 2; // Find the middle point of the current range

        if(isValid(arr, n, c, mid)){
            st = mid + 1; // Try to increase the minimum distance
            ans = mid; // Update the answer
        } else {
            ed = mid - 1; // Decrease the distance
        }
    }

    return ans; // Return the largest minimum distance
}

int main(){
    int stalls = 5, cows = 3;
    vector<int> loc = {1, 2, 8, 4, 9};

    cout << largestMinDist(loc, stalls, cows) << endl; // Output the result

    return 0;
}

/**
 * Time Complexity:
 * 1. Sorting the stall locations takes O(N log N), where N is the number of stalls.
 * 2. The binary search loop runs in O(log D) time, where D is the difference between the maximum and minimum stall locations.
 * 3. The isValid function runs in O(N) time for each iteration of the binary search.
 *    Thus, the total time complexity is O(N log N + N log D).
 * 
 * Space Complexity:
 * 1. The space complexity is O(1) as we are using only a constant amount of extra space.
 */
