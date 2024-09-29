#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int> arr, int target){
    vector<int> ans;
    int smallpt = 0, bigpt=arr.size();

    while(smallpt<bigpt){ 
        int pairsum = (arr[smallpt]+arr[bigpt]);
        if(pairsum > target){
            bigpt--;
        } 
        else if(pairsum < target){
            smallpt--;
        }
        else{
            ans.push_back(arr[smallpt]);
            ans.push_back(arr[bigpt]);
            return ans;
        }
    }
    return ans;
}

int majorityElement(vector<int> arr){
    int len = arr.size();
    int freq = 0; 
    int ans = arr[0];

    for(int num : arr){
        if(freq == 0){
            ans = num;
        }
        if(ans == num){
            freq++;
        } else {
            freq--;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {2,7,11,13};
    int target = 9;
    
    vector<int> ans = pairSum(arr, target);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    vector<int> arr2 = {2,2,1,1,1,2,2};

    cout << "Majority element is: " <<majorityElement(arr2) << endl;

    return 0;
}