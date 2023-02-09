#include<iostream>
using namespace std;

int ReverseNo(int num)
{
    int i,rev=0;
    for(i=num;i>0;i/=10)
    {
        //Formula to create the reverse of a number.
        rev=(rev*10)+(i%10);
    }
    return rev;
}

int main()
{
    int num;
    cout<<"Enter the number: "<<endl;
    cin>>num;
    cout<<"Reversed Number: "<<ReverseNo(num)<<endl;
}