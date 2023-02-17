#include<iostream>
using namespace std;

//A function to print the array elements.
void printArray(int arr[],int size)
{
    //Using the for loop for printing the elements of the array.
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

//Function two swap the array elements using add and subtract concept.
void swapAddSub(int arr[],int size)
{
    //Making use two pointer approach.
    int start=0;
    int end=size-1;
    while(start<=end)
    {
        //Adding and subtacting the two elements to swap them.
        arr[end]=arr[start]+arr[end];
        arr[start]=arr[end]-arr[start];
        arr[end]=arr[end]-arr[start];
        //Increment and decrement of start and end respectively.
        start++;
        end--;
    }
    printArray(arr,size);
}

//A function to swap the array elements using the temporary variable.
void swapUsingTemp(int arr[],int size)
{
    //Temporary variable.
    int temp;
    //Iterating the loop from 0 to size/2 and swapping the array elements.
    for(int i=0;i<size/2;i++)
    {
        //Using temp as a third variable helping to swap the elements.
        temp=arr[i];
        arr[i]=arr[size-i-1];
        arr[size-i-1]=temp;
    }
    printArray(arr,size);
}

//A function to swap the array elements using Bitwise XOR. 
void swapXOR(int arr[],int size)
{
    int start=0;
    int end=size-1;
    
}

//Main function
int main()
{
    int arr[]={1,2,3,4,5};
    int brr[]={6,7,8,9,10};
    int crr[]={11,12,13,14,15};
    int size=5;
    //Function calling.
    cout<<"Swapping using Add Subtract methodolgy."<<endl;
    swapAddSub(arr,size);
    cout<<"Swapping using temporary variable."<<endl;
    swapUsingTemp(brr,size);
    cout<<"Swapping using Bitwise XOR."<<endl;
}