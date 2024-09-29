#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int val = 0;
    for(int num: nums){
        val = val^num;
    }
    return val;
}

int reverseVecor(vector<int>& nums){
    int start = 0;
    int end = nums.size()-1;

    while(start<end){
        swap(nums.at(start), nums.at(end));
        start++;
        end--;
    }
    return 0;
}

int main(){
    vector<int> vec = {1,2,3,4};
    cout << "Size: " << vec.size() << endl;
    cout<<singleNumber(vec)<<endl;
    reverseVecor(vec);

    for(int num:vec){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}