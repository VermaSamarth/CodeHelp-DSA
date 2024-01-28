#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;
    if(n % 2 == 0)
        cout << "Smallest Multiple: " << n << endl;
    else    
        cout << "Smallest Multiple: " << n*2 << endl;
}