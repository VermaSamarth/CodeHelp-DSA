#include<iostream>
using namespace std;

int factorial(int num)
{
    int i,fact=1;
    for(i=1;i<=num;i++)
    {
        fact*=i;
    }
    return fact;
}

int combination(int n,int r)
{
    return (factorial(n)/((factorial(r)*factorial(n-r))));
}

int main()
{
    int count,row,space,col;
    cout<<"Enter the number of rows-column: "<<endl;
    cin>>count;
    cout<<"Pattern: "<<endl;
    for(row=0;row<count;row++)
    {
        for(space=0;space<count-row;space++)
        {
            cout<<" ";
        }

        for(col=0;col<=row;col++)
        {
            cout<<combination(row,col)<<" ";
        }
        cout<<endl;
    }
}