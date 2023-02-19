#include<iostream>
#include<vector>
using namespace std;

void CommonThreeSortedArray(vector<int> arr,vector<int> brr,vector<int> crr)
{
    int i,j,k;
    i=j=k=0;
    cout<<"Common Elements are ";
    while(i<arr.size()&&j<brr.size()&&k<crr.size())
    {
        if((arr[i]==brr[j])&&(brr[j]==crr[k]))
            cout<<arr[i]<<" ";
        if(arr[i]<brr[j])
            i++;
        else if(brr[j]<crr[k])
            j++;
        else
            k++;
    }
}
int main()
{
    vector<int> arr={1,5,10,20,40,80};
    vector<int> brr={6,7,20,80,100};
    vector<int> crr={3,4,15,20,30,70,80,120};
    CommonThreeSortedArray(arr,brr,crr);
    return 0;
}