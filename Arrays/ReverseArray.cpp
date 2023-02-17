#include<iostream>
using namespace std;
int main()
{
    // int arr[]={10,20,30,40,50,60,70,80,90,100,110};
    // int size=11;
    
    //Standard way of swapping using for loop and swap function.
    //Iterating the loop from 0 to size/2 and swapping the array elements.

    // for(int i=0;i<size/2;i++)
    // {
    //     swap(arr[i],arr[size-i-1]);
    // }


    //Method of using Two pointers approach.
    //We make use of start and end of the array.
    int arr[]={10,20,30,40,50,60,70,80,90,100,110};
    int size=11;
    //start pointer is initialized by 0 and the end pointer is initialisd by size-1.
    int start=0;
    int end=size-1;
    //Loop will work until the start and end pointer cross each other.
    while(start<=end)
    {
        swap(arr[start],arr[end]);
        //Increment of start pointer.
        start++;
        //Decrement of the end pointer.
        end--;
    }

    for(int i=0;i<size;i++)
        cout<<arr[i]<<endl;

    return 0;
}