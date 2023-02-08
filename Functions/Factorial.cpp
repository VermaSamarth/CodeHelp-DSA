#include<iostream>
using namespace std;

int FactorialNumber(int num)
{
    int i,fact=1;
    for(i=1;i<=num;i++)
    {
        fact*=i;
    }
    return fact;
}

int main()
{
    int num;
    cout<<"Enter the number: "<<endl;
    cin>>num;
    cout<<"Factorial = "<<FactorialNumber(num)<<endl;
    return 0;
}