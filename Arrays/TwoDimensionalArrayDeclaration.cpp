#include<iostream>
using namespace std;
int main()
{
    //Declaration of the 2D Array
    int arr[3][3];

    //Declaration and Initialiazation of 2D Array. 
    int brr[3][3]={{1,2,3},{4,5,6},{7,8,9}};

    // col0     col1   col2
    //  1       2       3       row0
    //  4       5       6       row1
    //  7       8       9       row2

    cout<<"Row-wise Access: "<<endl;

    //Printing the array row-wise
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<brr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"Column-wise access: "<<endl;
    //Printing the array column-wise
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<brr[j][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}