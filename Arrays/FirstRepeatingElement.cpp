#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int firstRepeating(int arr[],int n)
{
    unordered_map<int,int>hash;
    for(int i=0;i<n;i++)
    {
        hash[arr[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(hash[arr[i]]>1)
            return i+1;
    }
    return -1;
}

int main()
{
    int arr[]={1,5,2,4,3,6,7,5,3};
    int n=sizeof(arr)/sizeof(int);
    cout<<"First repeating is at index: "<<firstRepeating(arr,n)<<endl;
}
