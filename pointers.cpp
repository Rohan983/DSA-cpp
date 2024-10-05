#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int* ptr = &a;
    int** parptr = &ptr;

    cout<< a << endl;           // 10
    cout<< &a << endl;          // address of a
    cout<< ptr << endl;         // address of a
    cout<< *ptr << endl;        // 10
    cout<< &ptr << endl;        // address of ptr
    cout<< parptr << endl;      // address of ptr 
    cout<< *parptr << endl;     // address of a
    cout<< **parptr << endl;    // 10
    cout<< &parptr << endl;     // address of parptr

    return 0;
}