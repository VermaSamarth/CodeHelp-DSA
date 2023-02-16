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
    cout<<"Enter the array 1 elements i.e., only 0's and 1's: "<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cin>>arr[i];
    }
    end=size-1;
    while (start<=end)
    {
        // cout<<"For i="<<i<<" and start="<<start<<" and end="<<end<<"."<<endl;
        // printArray(arr);
        if(arr[i]==0)
        {
            // cout<<"Found Zero"<<endl;
            // cout<<"Before Swap."<<endl;
            // printArray(arr);
            swap(arr[i],arr[start]);
            // cout<<"After Swap."<<endl;
            start++;
            i++;
            // printArray(arr);
            // cout<<"After Swapping, i="<<i<<" and start="<<start<<" and end="<<end<<"."<<endl;
        }
        else
        {
            // cout<<"Found One"<<endl;
            // cout<<"Before Swap."<<endl;
            // printArray(arr);
            swap(arr[i],arr[end]);
            end--;
            // cout<<"After Swap."<<endl;
            // printArray(arr);
            // cout<<"After Swapping, i="<<i<<" and start="<<start<<" and end="<<end<<"."<<endl;
        }
    }
    cout<<"Final Sorted Array:";
    printArray(arr);
    return 0;
}