#include<iostream>
#include<limits.h>
using namespace std;

int MaxInArray(int arr[][3],int rows, int cols)
{
    int max=INT_MIN;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(max<arr[i][j])
                max=arr[i][j];
        }
    }
    return max;
}

int MinInArray(int arr[][3],int rows, int cols)
{
    int min=INT_MAX;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(min>arr[i][j])
                min=arr[i][j];
        }
    }
    return min;
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
    cout<<"Maximum in 2D Array: "<<MaxInArray(arr,3,3)<<endl;
    cout<<"Minimum in 2D Array: "<<MinInArray(arr,3,3)<<endl;
    return 0;
}