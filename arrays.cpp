#include <iostream>
using namespace std;

int reverseArray(int arr[], int size){
    // for(int i=0; i < size/2; i++){
    //     swap(arr[i], arr[size-i-1]);
    // }
    
    // Two Pointer Approach
    int start = 0, end = size-1;

    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    return 0;
}   

int swapMnMx(int arr[], int size){
    int smalli, bigi = 0;
    for(int i = 0; i < size; i++){
        if(arr[i]<arr[smalli]){
            smalli = i;
        }
        if(arr[i]>arr[bigi]){
            bigi = i;
        }
    }
    swap(arr[smalli], arr[bigi]);
    return 0;
}


int uniqueVals(int arr[], int size){
    for(int i=0; i<size; i++){
        bool count=true;
        for(int j=0; j<size; j++){
            if(arr[i]==arr[j] && (i != j)){
                count = false;
                break;
            }
        }
        if(count)
            cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

int main(){
    int size = 12;
    int arr[] = {1,2,3,4,1,2,3,45,5,5,5,9};
    // int small = INT_MAX;
    // int big = INT_MIN;
    // int smalli, bigi = 0;
    // for(int i = 0; i < size; i++){
    //     if(arr[i]<arr[smalli]){
    //         smalli = i;
    //     }
    //     if(arr[i]>arr[bigi]){
    //         bigi = i;
    //     }
    //     small = min(arr[i],small);
    //     big = max(arr[i],big);
    // }

    // cout << "Smallest number is: " << small << " at "<< smalli << endl;
    // cout << "Biggest number is: " << big << " at "<< bigi << endl;

    for (int i=0; i<size; i++)
        cout << arr[i] << " ";
    cout<<endl;
    // reverseArray(arr, size);
    // swapMnMx(arr, size);
    // for (int i=0; i<size; i++)
    //     cout << arr[i] << " ";
    // cout<<endl;

    uniqueVals(arr, size);
    return 0;
}