#include<iostream>
using namespace std;
int main(){
    int a = 5;
    //Creating a reference variable
    int& b = a;
    cout<<"Before update: "<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    
    a++;

    cout<<"After update: "<<endl;
    cout<<a<<endl;
    cout<<b<<endl;

    cout<<"Memory Location: "<<endl;
    cout<<"a = "<<&a<<endl;
    cout<<"b = "<<&b<<endl;
}