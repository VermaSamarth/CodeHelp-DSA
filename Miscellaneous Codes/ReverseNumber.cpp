#include<iostream>
using namespace std;

int reverse(int& n){
    int rev = 0;
    for(int i = n; i != 0; i/=10){
        rev = (rev * 10) + (i % 10);
    }
    return rev;
}

int main(){
    int num;
    cout << "Enter the number: " << endl;
    cin >> num;
    cout << reverse(num) << endl;
}