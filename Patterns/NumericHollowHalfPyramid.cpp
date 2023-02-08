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
        //Condition check to make sure its not the last row.
        if(row<count-1)
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
                if(col==0)
                    cout<<"1";
                else if(col==(2*row))
                    cout<<row+1;
                else
                {
                    cout<<" ";
                }
            }
            cout<<endl;
        }
        //Printing the last line of the pattern 
        else
        {
            for(col=0;col<(2*row+1);col++)
            {
                //For alternate printing of star and spaces.
                if(col%2==0)
                    cout<<(col/2)+1;
                else
                    cout<<" ";
            }
            cout<<endl;
        }
        
    }
}
