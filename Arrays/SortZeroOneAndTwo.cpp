#include<iostream>
#include<vector>
using namespace std;

void printArray(vector <int> arr)
{
    for(auto value:arr)
        cout<<value<<" ";
    cout<<endl;
}

int main()
{
    int size,i=0,start=0,end;
    cout<<"Enter the size of the array: "<<endl;
    cin>>size;
    vector <int> arr(size);
    cout<<"Enter the array 1 elements i.e., only 0's, 1's and 2's: "<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cin>>arr[i];
    }
    cout<<"Before Sorting: "<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"After Sorting: "<<endl;
    end=size-1;
    while (start<=end)
    {
        if(arr[i]==0)
        {
            swap(arr[i],arr[start]);
            start++;
            i++;
        }
        else
        {
            
        }
    }
    cout<<"Final Sorted Array:";
    printArray(arr);
    return 0;
}