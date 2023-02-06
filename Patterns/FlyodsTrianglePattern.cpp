#include<iostream>
using namespace std;
int main()
{
    int inc=0,count,col,row;
    cout<<"Enter the number of rows-columns: "<<endl;
    cin>>count;
    cout<<"Pattern: "<<endl;
    for(row=0;row<count;row++)
    {
        for(col=0;col<row+1;col++)
        {
            cout<<++inc<<" ";
        }
        cout<<endl;
    }
}