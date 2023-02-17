#include<iostream>
using namespace std;

//Function to find the transpose of a matrix
void TransposeMatrix(int arr[][3],int rows,int cols)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=i;j<cols;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
}

void PrintingMatrix(int arr[][3],int rows,int cols)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
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
    cout<<"Array before Transposing:"<<endl;
    PrintingMatrix(arr,3,3);
    cout<<"Array after Transposing: "<<endl;
    TransposeMatrix(arr,3,3);
    PrintingMatrix(arr,3,3);
    return 0;
}