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
        if(arr[i]<0)
        {
            swap(arr[i],arr[start]);
            start++;
            i++;
        }
        else
        {
            swap(arr[i],arr[end]);
            end--;
        }
    }
    cout<<"After moving -ve numbers to on side(left):";
    printArray(arr);
    return 0;
}