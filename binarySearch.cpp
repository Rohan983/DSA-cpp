#include <iostream>
#include <vector>
using namespace std;

// Iterative Binary Search
int binarySearch(vector<int> arr, int target){
    int st = 0, ed = arr.size()-1;

    while(st<=ed){
        /* First formula may lead to overflow if ed and st both became *
         * INT_MAX, we should use second formula to calculate mid to   *
         * avoid this edge condition. Simplifiaction :                 *
         * (ed+st)/2 => (2st+ed-st)/2 => 2st/2 + (ed-st)/2             *
         *           => st + (ed-st)/2                                 */
        // int mid = (ed+st)/2; 
        int mid = st + (ed-st)/2;

        if(arr[mid] == target){
            return mid;
        } 
        
        if(arr[mid] < target){
            st = mid+1;
        } else {
            ed = mid-1;
        }
    }  

    return -1;
}

int main(){
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // Odd size
    int tar1 = 12; 

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12};    // Even size
    int tar2 = 0;

    cout << "1. Target Position: " << binarySearch(arr1, tar1) << endl;
    cout << "2. Target Position: " << binarySearch(arr2, tar2) << endl;

    return 0;
}