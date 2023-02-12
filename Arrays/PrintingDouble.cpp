#include<iostream>
using namespace std;

int main()
{
    int arr[100];
    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    cout<<"Enter the array elements: "<<endl;
    //Inputiing the 10 numbers using the for loop.
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    //Printing the doubles of the array elements using for loop.
    cout<<"Doubles of the array elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<(2*arr[i])<<endl;
    }
    return 0;
}