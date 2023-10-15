#include<iostream>
using namespace std;
void update(int** q){
    //q = q + 1;  
    //Change in the location stored in ptr2 but it won't be reflected (Works as pass by value).
    
    //*q = *q + 1;
    //Change in the location stored in ptr1 but the value of a remains the same.
    
    **q = **q + 1;
    //Chnage in the value stored in a but ptr1 and ptr2 remains the same.

    // **q = *q + 1; 
    //Throws an error.
}

int main(){
    int a = 10;
    int* ptr1 = &a;
    int** ptr2 = &ptr1;

    cout<<"Before Values: "<<endl;
    cout<<ptr1<<endl;
    cout<<*ptr1<<endl;
    cout<<ptr2<<endl;
    cout<<**ptr2<<endl;

    update(ptr2);
    
    cout<<"After Values: "<<endl;
    cout<<ptr1<<endl;
    cout<<*ptr1<<endl;
    cout<<ptr2<<endl;
    cout<<**ptr2<<endl;
}