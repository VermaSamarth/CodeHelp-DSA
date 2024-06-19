#include<iostream>
using namespace std;

int main(){
    int a, b;
    cout << "Enter the value of a & b: ";
    cin >> a >> b;
    int x = a;
    int quot, rem, y1 = 0, y2 = 1, y;
    while(a != 1){
        quot = a / b;
        rem = a % b;
        y = y1 - (y2 * quot);
        a = b;
        b = rem;
        y1 = y2;
        y2 = y;
    }
    if(y1 < 0)
        cout << "Multiplicative Inverse = " << (x + y1) << endl;
    else
        cout << "Multiplicative Inverse = " << y1 << endl;
}