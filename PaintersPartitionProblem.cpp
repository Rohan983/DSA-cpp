/** The Painter’s Partition Problem : GeeksforGeeks 
 * https://www.geeksforgeeks.org/painters-partition-problem/ **/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Function to check if it is possible to divide the array into parts such that the maximum part sum is less than or equal to maxPart
bool isValid(int N, vector<int> A, int K, int maxPart){
    int workers = 1; // Start with one worker
    int part = 0; // Current part sum

    for(int ele : A){
        if(ele > maxPart) return false; // If an element is greater than maxPart, it is not possible to divide

        if(part+ele <= maxPart){
            part += ele; // Add element to the current part
        } else {
            workers++; // Need an additional worker
            part = ele; // Start a new part with the current element
        }
    }

    return workers > K ? false : true; // Return true if the number of workers needed is less than or equal to K
}

// Function to find the minimum time to complete the tasks with K workers
int minTime(int N, vector<int> A, int K){
    if(N<K) return -1;

    int st = INT_MIN, ed = 0, ans = -1;
    for(int ele : A){
        ed += ele; // Calculate the total sum of elements
        st = max(st, ele);
    }

    while(st<=ed){
        int mid = st + (ed - st)/2; // Find the middle point

        if(isValid(N, A, K, mid)){
            ed = mid - 1; // Try to minimize the maximum part sum
            ans = mid;
        } else {
            st = mid + 1; // Increase the maximum part sum
        }
    }

    return ans; // Return the minimum time
}

int main(){
    int N = 4, K = 2;
    vector<int> A = {40,30,10,20};

    cout << minTime(N, A, K) << endl; // Output the result

    return 0;
}
