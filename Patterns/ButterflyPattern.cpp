#include<iostream>
using namespace std;
int main()
{
    int count,row,col,space;
    cout<<"Enter the number of rowa-columns: "<<endl;
    cin>>count;
    for(row=0;row<count;row++)
    {
        //Loop for the number of columns for upper left.
        for(col=0;col<row+1;col++)
        {
            cout<<"*";
        }
        //Loop for spacing in the upper half.
        for(space=0;space<(2*count)-2-(2*row);space++)
        {
            cout<<" ";
        }
        //Loop for the number of columns for upper right.
        for(col=0;col<row+1;col++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    for(row=0;row<count;row++)
    {
        //Loop for the number of columns for lower left.
        for(col=0;col<count-row;col++)
        {
            cout<<"*";
        }
        //Loop for spacing in the lower half.
        for(space=0;space<(2*row);space++)
        {
            cout<<" ";
        }
        //Loop for the number of columns for lower right.
        for(col=0;col<count-row;col++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}