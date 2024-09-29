#include <iostream>
using namespace std;

int sumOfNumbers(int n){
    int sum = (n*(n+1))/2;
    return sum;
}

int factorialN(int n){
    int fact = 1;

    for (int i=1; i<=n; i++){
        fact *= i;
    }
    return fact;
}

int sumOfDIgits(int n){
    int digitSum = 0;

    while (n>0){
        digitSum += n % 10;
        n = int(n / 10);
    }
    return digitSum;
}

double nCr(int n, int r){
    return double(factorialN(n)/(factorialN(r) * factorialN(n-r)));
}

void fibonacci(int n){
    int first = 0;
    int second = 1;
    int num;
    cout << first << " " << second << " ";
    for (int i = 2; i < n; i++){
        num = first + second;
        cout << num << " " ;
        first = second;
        second = num; 
    }
    return;
}

int main(){
    //sumOfNumbers(3);
    cout << factorialN(5) << endl;
    cout << sumOfDIgits(162340) << endl;
    cout << nCr(6,3) << endl;
    fibonacci(4);
    return 0;
}