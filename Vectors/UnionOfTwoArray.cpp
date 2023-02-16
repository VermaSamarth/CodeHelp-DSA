#include<iostream>
#include<vector>
using namespace std;

//The two array must contain the unique elements and no common elements among the two arrays. 
int main()
{
    int size1,size2;
    cout<<"Enter the size of the array 1: "<<endl;
    cin>>size1; 
    cout<<"Enter the size of the array 2: "<<endl;
    cin>>size2; 
    vector <int> arr(size1);
    vector <int> brr(size2);
    vector <int> crr;
    cout<<"Enter the array 1 elements: "<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the array 2 elements: "<<endl;
    for(int i=0;i<brr.size();i++)
    {
        cin>>brr[i];
    }
    for(int i=0;i<arr.size();i++)
    {
        crr.push_back(arr[i]);
    }
    for(int i=0;i<brr.size();i++)
    {
        crr.push_back(brr[i]);
    }

    cout<<"Union of the elements of array 1 and array 2 is ";
    for(int i=0;i<crr.size();i++)
    {
        cout<<crr[i]<<" ";
    }
    cout<<endl;

    return 0;
}