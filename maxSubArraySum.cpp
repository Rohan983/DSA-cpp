#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 7;
    int arr[n] = {3,-4,5,4,-1,7,-8};
    int max_sum = INT_MIN;

    // Brute Force
    // for(int st=0; st<n; st++){
    //     int curr_sum = 0;
    //     for(int en=st; en<n; en++){
    //         if(en-st>=4){
    //             break;
    //         }
    //         curr_sum += arr[en];
    //         max_sum = max(max_sum, curr_sum);
    //     }
    // }

    // Kadane's Algorithm
    int curr_sum = 0;
    for (int st=0; st<n; st++){
        curr_sum +=arr[st];
        max_sum = max(curr_sum, max_sum);
        if(curr_sum<0){
            curr_sum = 0;
        }
    }

    cout<<max_sum<<endl;
    return 0;
}