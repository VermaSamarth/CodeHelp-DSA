#include<iostream>
#include<vector>
using namespace std;

void findMissing(int arr[],int n)
{
    //visited method
    /*
    for(int i=0;i<n;i++)
    {
        int index=abs(arr[i]);
        if(arr[index-1]>0)
        {
            arr[index-1]*=-1;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
            cout<<i+1<<" ";
    }
    */
    
    //Swapping and Sortinf method
    int i=0;
    while(i<n)
    {
        int index=arr[i]-1;
        if(arr[i]!=arr[index])
        {
            swap(arr[i],arr[index]);
        }
        else
        {
            ++i;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=i+1)
            cout<<i+1<<" ";
    }

}

int main()
{
    //int arr[]={1,3,5,3,4};
    // int arr[]={1,3,5,5,5};
    int arr[]={3,3,3,3,3};
    int n=sizeof(arr)/sizeof(int);
    findMissing(arr,n);
    return 0;
}