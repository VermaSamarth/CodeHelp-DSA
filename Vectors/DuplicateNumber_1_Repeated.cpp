#include<iostream>
#include<vector>
using namespace std;

int DuplicateElement(vector<int> arr)
{
    while(arr[0]!=arr[arr[0]])
        swap(arr[0],arr[arr[0]]);
    return arr[0];
}

int main()
{
    int size;
    cout<<"Enter the size of the array: "<<endl;
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the array elements and only one number as duplicate and inputs should be less than the size of the arry: "<<endl;
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
    cout<<"Duplicate:"<<DuplicateElement(arr)<<endl;    
    return 0;
}