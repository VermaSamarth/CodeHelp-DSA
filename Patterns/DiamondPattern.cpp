#include<iostream>
using namespace std;
int main()
{
    int space,count,row,col;
    //Inputting the number of rows-columns.
    cout<<"Enter the size of row-column: "<<endl;
    cin>>count;
    cout<<"Pattern: "<<endl;

    //Loop for the number of rows for upper pyramid.
    for(row=0;row<count;row++)
    {
        //Loop for the number of spaces for upper pyramid.
        for(space=0;space<count-row-1;space++)
        {
            cout<<" ";
        }
        //Loop for the number of columns for upper pyramid.
        for(col=0;col<(2*row+1);col++)
        {
            //For alternate printing of star and spaces for upper pyramid.
            if(col%2==0)
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
        for(space=0;space<=row;space++)
        {
            cout<<" ";
        }
        //Loop for the number of columns for lower pyramid.
        for(col=0;col<(2*count)-1-(2*space);col++)
        {
            //For alternate printing of star and spaces for upper pyramid.
            if(col%2==0)
                cout<<"*";
            else
                cout<<" ";
        }
        cout<<endl;
    }
}