#include<iostream>
#include<vector>
using namespace std;

void PrintingArray(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void LeftRotate(vector<int> arr)
{
    int first=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        arr[i-1]=arr[i];
    }
    arr.pop_back();
    arr.push_back(first);
    PrintingArray(arr);
}


int main()
{
    vector<int> arr(10);
    cout<<"Enter the elements in the vector: "<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cin>>arr[i];
    }
    LeftRotate(arr);
    return 0;
}