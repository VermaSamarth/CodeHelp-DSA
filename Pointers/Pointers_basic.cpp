/*
* Here in this code, we are learning about the basics of the pointer.
*/

#include<iostream>
using namespace std;
int main(){
    int a=9;
    int* ptr=&a;
    cout<<"Value of the variable a: "<<a<<endl;
    cout<<"Memory location of the variable a: "<<ptr<<endl;

    int b=10;
    int* p=&b;

    cout<<"Value of the variable b: "<<b<<endl;
    cout<<"Memory location of the variable b: "<<p<<endl;
    b=b+1;
    p=p+1;

    cout<<"New Value of the variable b: "<<b<<endl;
    cout<<"New Memory location of the variable b: "<<p<<endl;
}