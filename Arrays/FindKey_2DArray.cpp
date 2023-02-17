#include<iostream>
using namespace std;

bool FindKey(int arr[][3],int rows, int cols, int key)
{
    //Loop for traversal in the 2D Array.
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(key==arr[i][j])
            return true;
        }
    }
    return false;
}

int main()
{
    //Declaration of the 2D Arrays
    int arr[3][3];
    int key;
    //Inputting elements in the array arr.
    cout<<"Enter the 2D Array elements row-wise: "<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"Enter the key to be searched: "<<endl;
    cin>>key;
    if(FindKey(arr,3,3,key))
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;
    return 0;
}