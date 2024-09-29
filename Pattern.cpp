#include <iostream>
using namespace std;

int main(){
    // char Ch;
    // cout << "Enter your Character: " ;
    // cin >> Ch;
    // if (int(Ch) >= 97){
    //     cout << "Lowercase" <<endl;
    // } else {
    //     cout << "Uppercase" <<endl;
    // }
    // cout << (int(Ch) >= 97 ? "Lowercase" : "Uppercase" )<< endl;
    // int n = 11;
    // bool prime = true;
    // for(int i=2; i*i<= n; i+=2) {
    //     if (n % i == 0){
    //         prime = false;
    //         break;
    //     }
    // }

    // if (prime == false) {
    //     cout << "Not a Prime Number" << endl;
    // } else {
    //     cout << "Prime Number" << endl;
    // }

    int  n = 4;
    // A B C D
    // A B C D
    // A B C D
    // A B C D
    // for (int i = 0; i < n; i++) {
    //     for (int j = 65; j < 65+n; j++) {
    //         cout << char(j) << " ";
    //     }
    //     cout << endl;
    // }

    // A B C D 
    // E F G H
    // I J K L
    // M N O P
    // for (int i = 0; i < n; i++) {
    //     for (int j = 65; j <65+n; j++) {
    //         cout << char(j+(i*n)) << " ";
    //     }
    //     cout << endl;
    // }

    // A 
    // B B
    // C C C
    // D D D D
    // for (int i =0; i < n; i++) {
    //     for (int j = 0; j < i+1; j++) {
    //         cout << char(i+ 65) << " ";
    //     }
    //     cout << endl;
    // }

    // A 
    // B A
    // C B A
    // D C B A
    // for (int i =0; i < n; i++) {
    //     for (int j = 0; j < i+1; j++) {
    //         cout << char(i-j+65)<< " ";
    //     }
    //     cout << endl;
    // }
    
    // 1 
    // 2 3
    // 4 5 6
    // 7 8 9 10
    // A 
    // B C 
    // D E F 
    // G H I J
    // int num = 1;
    // for (int i =0; i < n; i++) {
    //     for (int j = 0; j < i+1; j++ ) {
    //         cout << char(num +64)<< " ";
    //         num++;
    //     }
    //     cout << endl;
    // }


    // 1 1 1 1
    //   2 2 2
    //     3 3
    //       4
    // for (int i =0; i < n; i++) {
    //     for (int j = 0; j < i; j++) {
    //         cout << "  ";
    //     }
    //     for (int j = 0; j < n-i; j++) {
    //         cout << i+1 << " ";
    //     }
    //     cout << endl;
    // }

    //    1
    //   121
    //  12321
    // 1234321
    // for (int i =0; i < n; i++) {
    //     for (int j = 0; j < n - i - 1; j++) {
    //         cout << " ";
    //     }
    //     for (int j = 0; j < i + 1; j++) {
    //         cout << j+1 ;
    //     }
    //     for (int j = i; j > 0; j--) {
    //         cout << j;
    //     }
    //     cout << endl;
    // }

    //    *
    //   * *
    //  *   *
    // *     *
    //  *   *
    //   * *
    //    *
    // for(int i = 0; i <n; i++) {
    //     for (int j = 0; j < n-i-1; j++) {
    //         cout << " ";
    //     }
    //     cout << '*';
    //     if (i != 0) {
    //         for (int j = 0; j < 2*i-1; j++) {
    //             cout << " ";
    //         }
    //         cout << '*';
    //     }
    //     cout << endl;
    // }

    // for(int i = 0; i < n-1; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << " ";
    //     }
    //     cout << '*';
    //     if(i != n-2){
    //         for (int j = 0; j <= n-(2*i)-1; j++) {
    //             cout << " ";
    //         }
    //         cout << '*';
    //     }
    //     cout << endl;
    // }


    // *      *
    // **    **
    // ***  ***
    // ********
    // ********
    // ***  ***
    // **    **
    // *      *
    //top
    for(int i = 0; i <n; i++) {
        for(int j = 0; j<=i; j++) {
            cout << "*";
        }
        for(int j = 0; j<2*(n-i)-2; j++) {
            cout << " ";
        }
        for(int j = 0; j<=i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    //bottom
    for(int i = 0; i <n; i++) {
        for(int j = 0; j<(n-i); j++) {
            cout << "*";
        }
        for(int j = 0; j<2*i; j++) {
            cout << " ";
        }
        for(int j = 0; j<(n-i); j++) {
            cout << "*";
        }
        cout << endl;
    } 
}   
