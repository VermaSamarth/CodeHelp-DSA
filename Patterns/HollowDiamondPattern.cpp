#include<iostream>
using namespace std;
int main()
{
    int count, space, row, col, output;
    //Inputting the size of the column-row
    cout<<"Enter the number of row-column: "<<endl;
    cin>>count;
    cout<<"Pattern: "<<endl;

    //Loop for the number of rows
    for(row=0;row<count;row++)
    {
        //Loop for the number of spaces
        for(space=0;space<count-row-1;space++)
        {
            cout<<" ";
        }
        //Loop for the number of columns
        for(col=0;col<(2*row)+1;col++)
        {
            //Conditions for prinitng the hollow part of the full pyramid
            if(col==0||col==(2*row))
                cout<<"*";
            else
                cout<<" ";
        }
        cout<<endl;
    }
    
    //Loop for the number of rows for lower pyramid.
    for(row=0;row<count;row++)
    {
        //Loop for the number of spaces for lower pyramid.
        for(space=0;space<row;space++)
        {
            cout<<" ";
        }
        //Loop for the number of columns for lower pyramid.
        for(col=0;col<(2*count)-1-(2*row);col++)
        {
            //Conditions for prinitng the hollow part for lower pyramid
            if(col==0||col==(2*count)-2-(2*row))
                cout<<"*";
            else
                cout<<" ";
        }
        cout<<endl;
    }
}