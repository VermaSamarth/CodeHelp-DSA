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
    cout<<"Pair sums are: "<<endl;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            for(int k=j+1;k<arr.size();k++)
            {
                if((arr[i]+arr[j]+arr[k])==sum)
                {
                    cout<<"("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<")"<<endl;
                }
            }
        }
    }
    cout<<endl;
    return 0;
}