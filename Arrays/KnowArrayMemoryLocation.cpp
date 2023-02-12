#include<iostream>
using namespace std;

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int brr[]={10,20,30,40,50};
    int crr[10]={11,12,13,14};
    // int drr[4]={1,2,3,4,5};   This will through an error and is invalid.

    //Creating array from a user defined size of the array. Explicitly inputting.
    int n;
    cout<<"Enter the array size: "<<endl;
    cin>>n;
    int a[n];
    cout<<"Array of size="<<n<<" has been created."<<endl;
    cout<<"BAD PRACTICE."<<endl<<endl;
    //This is a bad Practice of inputting the array size this way.

    //To find the memory location just simply write the array variable number.
    cout<<"Array a is stored from the location: "<<a<<endl; 
    cout<<"Array arr is stored from the location: "<<arr<<endl;
    cout<<"Array brr is stored from the location: "<<brr<<endl;
    cout<<"Array crr is stored from the location: "<<crr<<endl;
    return 0;
}