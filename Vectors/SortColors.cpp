#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cout<<"Enter the size of the vector: "<<endl;
    cin>>size;
    vector<int>arr(size);
    cout<<"Enter the array elements i.e. 0,1 and 2: "<<endl;
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
        
    cout<<"Unsorted Array: "<<endl;
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    
    //Using standard template library (STL) function sort.
    /*
    sort(arr.begin(),arr.end());
    */
    

    //Counting Sort method.
    /*
    int zeros=0,ones=0,twos=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==0)
            zeros++;
        else if(arr[i]==1)
            ones++;
        else
            twos++;
    }

    int i=0;
    while(zeros--)
        arr[i++]=0;
    while(ones--)
        arr[i++]=1;
    while(twos--)
        arr[i++]=2;
    */
    
   //In-place sort: Using 3 pointer approach
   int low=0,mid=0,high=arr.size()-1;

    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }

   
    cout<<"Sorted Array: "<<endl;
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}