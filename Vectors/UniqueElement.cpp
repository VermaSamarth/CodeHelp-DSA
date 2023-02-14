#include<iostream>
#include<vector>
using namespace std;

int FindUnique(vector <int> arr)
{
    int ans;
    for(int i=0;i<arr.size();i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}

int main()
{
    int num;
    cout<<"Enter the size of the array: "<<endl;
    cin>>num;
    vector <int> arr(num);
    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cin>>arr[i];
    }
    
    int UniqueNumber = FindUnique(arr);
    cout<<"Unique Number: "<<UniqueNumber<<endl;

    return 0;
}