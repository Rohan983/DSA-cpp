#include <iostream>
using namespace std;

int decToBin(int num){
    int binary = 0, power = 1;
    
    while (num > 0){
        binary += (num%2) * power;
        num /= 2;
        power = power *10;
    }
    return binary;
}

int binToDec(int num){
    int decimal = 0, power = 1;
    
    while (num > 0){
        decimal += (num%10) * power;
        num /= 10;
        power = power *2;
    }
    return decimal;
}

bool isPowerOfTwo(int num){
    while(num > 0){
        if (num == 2){
            return true;
        }
        num = (num >> 1);
        cout << num << endl;
    }
    return false;
}

int main(){
    // for (int i = 1; i <=10; i++){
    //     cout << decToBin(i) << endl;
    // }
    // cout << decToBin(12) <<endl;
    // isPowerOfTwo(32);
    cout << isPowerOfTwo(34) << endl;

}