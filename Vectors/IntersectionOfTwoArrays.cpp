#include<iostream>
#include<vector>
using namespace std;

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
        for(int j=0;j<brr.size();j++)
        {
            if(arr[i]==brr[j])
            {
                brr[j]=INT_MIN;
                crr.push_back(arr[i]);
            }
        }
    }
    cout<<"Intersection of the elements of array 1 and array 2 is ";
    for(auto value:crr)
    {
        cout<<value<<" ";
    }
    cout<<endl;
    return 0;
}