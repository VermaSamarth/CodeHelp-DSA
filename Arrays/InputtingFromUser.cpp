#include<iostream>
using namespace std;
int main()
{
    int arr[10];
    cout<<"Enter the 10 elements of the array: "<<endl;
    
    //Inputiing the 10 numbers using the for loop.
    for(int i=0;i<10;i++)
    {
        cin>>arr[i];
    }

    //Printing the array elements using for loop.
    for(int i=0;i<10;i++)
    {
        cout<<"Array Element at index "<<i<<": "<<arr[i]<<endl;
    }
    return 0;
}