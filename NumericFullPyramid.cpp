#include<iostream>
using namespace std;
int main()
{
    int count, space, row, col, output;
    //Inputting the size of the column-row
    cout<<"Enter the size of the row-column matrix: "<<endl;
    cin>>count;
    cout<<"Pattern: "<<endl;

    //Loop for the number of rows
    for(row=0;row<count;row++)
    {
        output=row;
        //Loop for the number of spaces
        for(space=0;space<count-row-1;space++)
        {
            cout<<" ";
        }
        //Loop for the number of columns(1st left Side)
        for(col=0;col<row+1;col++)
        {
            cout<<++output;
        }
        //Loop for the number of columns(2nd Right Side)
        for(col=0;col<row;col++)
        {
            cout<<--output;
        }
        cout<<endl;
    }
}