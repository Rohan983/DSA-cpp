// Find two lines that together with the x-axis form a container, 
// such that the container contains the most water.

#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
    // Brute Force
    // int max_area = 0;
    // for(int i=0; i<height.size(); i++){
    //     for(int j=i; j<height.size(); j++){

    //         max_area = max(max_area, min(height[i], height[j]) * (j-i));
    //     }
    // }
    // return max_area;


    // Two Pointer Method
    int max_area = 0, lhs=0, rhs=height.size() - 1;

    while(lhs<rhs){
        if(height[lhs]<height[rhs]){
            max_area = max(max_area, height[lhs] * (rhs-lhs));
            lhs++;
        } else {
            max_area = max(max_area, height[rhs] * (rhs-lhs));
            rhs--;
        } 
    }
    return max_area;
}

int main(){
    vector<int> height ={1,8,6,2,5,4,8,3,7};
    cout << "Max Area: " << maxArea(height) << endl;
    return 0;
}