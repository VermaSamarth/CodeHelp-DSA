#include<iostream>
using namespace std;

void PrintRowSum(int arr[][3],int rows,int cols)
{
    int sum=0;
    for(int i=0;i<rows;i++)
    {
        sum=0;
        for(int j=0;j<cols;j++)
        {
            sum=sum+arr[i][j];
        }
        cout<<"Sum of row="<<i<<" is "<<sum<<endl;
    }
}

void PrintColumnSum(int arr[][3],int rows,int cols)
{
    int sum=0;
    for(int i=0;i<rows;i++)
    {
        sum=0;
        for(int j=0;j<cols;j++)
        {
            sum=sum+arr[j][i];
        }
        cout<<"Sum of column="<<i<<" is "<<sum<<endl;
    }
}

int main()
{
    //Declaration of the 2D Arrays
    int arr[3][3];
    
    //Inputting elements in the array arr.
    cout<<"Enter the 2D Array elements row-wise: "<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    PrintRowSum(arr,3,3);
    PrintColumnSum(arr,3,3);
    return 0;
}