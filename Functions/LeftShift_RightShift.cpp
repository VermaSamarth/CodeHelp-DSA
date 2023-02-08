#include<iostream>
using namespace std;

int LeftShift(int num1)
{
    num1=num1<<1;
    return num1;
}

int RightShift(int num2)
{
    num2=num2>>1;
    return num2;
}

 int main()
 {
    int num1,num2,count,i;
    cout<<"Enter the number whose left shift is to be found: "<<endl;
    cin>>num1;
    cout<<"Enter the number whose right shift is to be found: "<<endl;
    cin>>num2;
    cout<<"How many you want to left shift and right shift?"<<endl;
    cin>>count;

    for(i=0;i<count;i++)
    {
        num1=LeftShift(num1);
        num2=RightShift(num2);
    }

    cout<<"Left Shift: "<<num1<<endl;
    cout<<"Right Shift: "<<num2<<endl;
 }