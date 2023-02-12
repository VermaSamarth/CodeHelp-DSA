#include<iostream>
using namespace std;

void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
    
}
int main()
{
    int arr[5]={1,2,3};
    int brr[5];
    int crr[5]={0};
    cout<<"Printing the array with 10 array elements but only 3 inputs."<<endl;
    cout<<"First 3 printed normally but remaining are printed as 0."<<endl;
    printArray(arr,5);
    cout<<"Printing the array with 10 array elements but no inputs."<<endl;
    cout<<"Garbage Values printed."<<endl;
    printArray(brr,5);
    cout<<"Printing the array with 10 elements but only one input i.e., 0."<<endl;
    cout<<"It is good way to initialize all elements in the array with 0."<<endl;
    printArray(crr,5);
    return 0;
}