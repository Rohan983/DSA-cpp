/** Allocate Minimum Pages : GeeksforGeeks 
 * https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1 **/

#include<iostream>
#include<vector>
#include<string>
using namespace std;


// Time Complexity: O(N), where N is the number of books. 
// We traverse through the books to allocate pages.
// Function to check if a given maximum page allocation is valid
bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages) {
    int students = 1; // Start with the first student
    int pages = 0;    // Track the pages allocated to the current student

    // Traverse through each book and allocate pages to students
    for(int ele: arr) {
        // If a single book has more pages than the allowed limit, return false
        if(ele > maxAllowedPages) return false;

        // If adding this book does not exceed the allowed limit, add it to the current student
        if(pages + ele <= maxAllowedPages) {
            pages += ele;
        } else {
            // Otherwise, allocate this book to the next student
            students++;
            pages = ele;
        }
    }

    // If the number of students required is greater than the allowed number, return false
    return students > m ? false : true;
}


// Time Complexity: O(N * log(S)), where N is the number of books and S is the sum of pages. 
// The binary search takes O(log(S)) and for each iteration, we perform O(N) operations to validate.
// Function to find the minimum possible maximum pages allocation
int findPages(int n, vector<int>& arr, int m) {
    // If there are fewer books than students, allocation is not possible
    if(n < m) return -1;

    int st = 0, ed = 0, ans = -1;
    // Calculate the sum of all pages (ed) to define the maximum limit
    for(int ele: arr) {
        ed += ele;
    }

    // Apply binary search between the maximum possible and the sum of all pages
    while(st <= ed) {
        int mid = st + (ed - st) / 2;

        // If it is possible to allocate books within this maximum limit, update the answer
        if(isValid(arr, n, m, mid)) {
            ed = mid - 1; // Try to find a smaller feasible value
            ans = mid;
        } else {
            st = mid + 1; // Increase the limit if it is not feasible
        }
    }

    return ans;
}

int main() {
    int noofBooks = 4, noofstudents = 2;
    vector<int> pages = {2, 1, 3, 4};
    
    // Output the result: minimum possible maximum pages allocation
    cout << findPages(noofBooks, pages, noofstudents) << endl;

    return 0;
}
