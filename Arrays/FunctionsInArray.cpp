#include<iostream>
using namespace std;
//PASS BY REFERENCE: We make changes in the actual array and the actual array is passed through the function.
//****Address of the array is passed using pointers.
//No copy of the function is created unlike Pass by Value.

//A function to print the array.
void printArray(int arr[],int size)
{
    //Using for loop to print the the array elements.
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
    
}

//A function to increament the array elements.
void inc(int arr[],int size)
{
    arr[0]++;
    arr[1]++;
    arr[2]++;
    cout<<"From the inc function."<<endl;
    printArray(arr,size);
}

//Main function.
int main()
{
    int arr[]={1,2,3};
    int size=3;

    //Using the concept of PASS BY REFERENCE to pass the array to the inc and printArray function.
    inc(arr,size);
    cout<<"From the main function."<<endl;
    printArray(arr,size);
    return 0;
}