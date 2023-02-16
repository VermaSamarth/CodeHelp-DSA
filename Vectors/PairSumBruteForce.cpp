#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int size,sum;
    cout<<"Enter the size of the array: "<<endl;
    cin>>size;
    vector <int> arr(size);
    cout<<"Enter the array 1 elements: "<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the sum you want to check: "<<endl;
    cin>>sum;
    cout<<"Pair sums are: ";
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            if((arr[i]+arr[j])==sum)
            {
                cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
            }
        }
    }
    cout<<endl;
    return 0;
}