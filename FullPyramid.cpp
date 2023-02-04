#include<iostream>
using namespace std;
int main()
{
    int space,count,row,col;
    //Inputting the number of rows-columns.
    cout<<"Enter the size of row-column: "<<endl;
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
        for(col=0;col<(2*row+1);col++)
        {
            //For alternate printing of star and spaces.
            if(col%2==0)
                cout<<"*";
            else
                cout<<" ";
        }
        cout<<endl;
    }
}