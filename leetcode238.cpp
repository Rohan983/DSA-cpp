#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> arr){
    for(int ele : arr){
        cout << ele << " ";
    }
    cout << endl;
}

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,1);

    /* Space complexity is not considered here,
     * Time complexity is O(3n) = O(n) */
    // vector<int> prefix(n, 1), suffix(n, 1);
    
    // for(int i=1; i<n; i++){
    //     prefix[i] = prefix[i-1] * nums[i-1];
    // }
    // // printVector(prefix);

    // for(int i=n-2; i>=0; i--){
    //     suffix[i] = suffix[i+1] * nums[i+1];
    // }
    // // printVector(suffix);

    // for(int i=0; i<n; i++){
    //     ans[i] = prefix[i] * suffix[i];
    // }


    /* With O(1) space complexity */
    int prefix = 1, suffix = 1;
    for(int i=0; i<n; i++){
        if(i!=0){
            prefix *= nums[i-1];
            suffix *= nums[n-i];
        }
            
        ans[i] *= prefix;
        ans[n-i-1] *= suffix;
    }

    return ans;
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> ans = productExceptSelf(nums);

    for(int a : ans){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}