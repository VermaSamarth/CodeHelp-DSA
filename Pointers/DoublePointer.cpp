#include<iostream>
using namespace std;

void util(int* ptr){
    ptr=ptr+1;
}

void util1(int* ptr1){
    //Value tabhi v+change hogi jab hum usko dereference karege
    //Value updated at the location
    *ptr1 = *ptr1 + 1;
    // *(location) = *(location) + 1
    // * => Value at the location.
}
int main(){
    int a=5;
    int* p=&a;
    int** q=&p;

    //Concept of Double pointer
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<*p<<endl;
    cout<<q<<endl;
    cout<<&q<<endl;
    cout<<*q<<endl;
    cout<<**q<<endl; //Value stored in the first location or 2 levels behind



    //Pass by value in pointers
    int num=5;
    int* ptr=&num;
    cout<<"\n\nBefore: num = "<<num<<", ptr = "<<ptr<<", *ptr =  "<<*ptr<<endl;
    util(ptr);
    cout<<"After: num = "<<num<<", ptr = "<<ptr<<", *ptr =  "<<*ptr<<endl;

    //
    int num1=5;
    int* ptr1=&num1;
    cout<<"\n\nBefore: num = "<<num1<<", ptr = "<<ptr1<<", *ptr =  "<<*ptr1<<endl;
    util1(ptr1);
    cout<<"After: num = "<<num1<<", ptr = "<<ptr1<<", *ptr =  "<<*ptr1<<endl;
}