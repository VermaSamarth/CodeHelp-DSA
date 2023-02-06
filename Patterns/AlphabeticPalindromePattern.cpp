#include<iostream>
using namespace std;
int main()
{
    int count,row,col;
    char ch;
    //Inputting the size of the column-row
    cout<<"Enter the number of rows-column: "<<endl;
    cin>>count;

    //Loop for the number of rows
    for(row=0;row<count;row++)
    {
        //Initializing ch with a value 1 less than 'A'
        ch=64;
        //Loop for the number of columns
        for(col=0;col<(2*row)+1;col++)
        {
            //Condition for prjnting the alphabets in palindrome order.
            if(col<=row)
                cout<<++ch;
            else
                cout<<--ch;
        }
        cout<<endl;
    }
}