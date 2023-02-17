#include<iostream>
#include<vector>
using namespace std;

int MajorityElement(vector<int>arr)
{
    for(int i=0;i<arr.size();i++)
    {
        int count=0;
        for(int j=i;j<arr.size();j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }
        if(count>(arr.size()/2))
            return arr[i];
    }
    return INT_MIN;
}

int main()
{
    int size;
    int value;
    cout<<"Enter the size of the vector: "<<endl;
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the array elements: "<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cin>>arr[i];
    }
    value=MajorityElement(arr);
    if(value==INT_MIN)
        cout<<"No Majority element present."<<endl;
    else   
        cout<<"Majority Element is "<<value<<endl;
}