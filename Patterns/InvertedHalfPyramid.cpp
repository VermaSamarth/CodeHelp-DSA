#include<iostream>
using namespace std;
int main()
{
    int count,row,col;
    //Inputting the size of the column-row
    cout<<"Enter the size of row-column: "<<endl;
    cin>>count;
    cout<<"Pattern: "<<endl;
    //Loop for the number of rows
    for(row=0;row<count;row++)
    {
        //Loop for the number of columns
        for(col=0;col<count-row;col++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}