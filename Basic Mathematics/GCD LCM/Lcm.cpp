#include<iostream>
using namespace std;
int main(){
    int num1,num2;
    cout<<"Enter the two number: "<<endl;
    cin>>num1>>num2;

    // Formula for LCM = (num1 * num2)/GCD
    int product=num1*num2;
    // Calculating the GCD using Euclid's Theorem
    // GCD(a,b) = GCD(a-b,b)        if a>b
    //            GCD(b-a,a)        if b>a

    if(num1==0)    
        cout<<"GCD = "<<num2<<endl;
    else if(num2==0)    
        cout<<"GCD = "<<num1<<endl;
    else{
        while(num1>0 && num2>0){
            if(num1>=num2)
                num1=num1-num2;
            else
                num2=num2-num1;
        }
        if(num1==0)
            cout<<"LCM = "<<(product)/num2<<endl;
        else
            cout<<"LCM = "<<(product)/num1<<endl;
    }
}