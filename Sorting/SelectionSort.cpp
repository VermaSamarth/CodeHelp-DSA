#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr{19,12,10,11,14};
    int n = size(arr);

    //Outer loop - (n-1) Rounds
    for(int i=0;i<n-1;i++){
        int minIndex = i;

        //Inner Loop - Index of minimun element in range i->n
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                //New minimum, the store
                minIndex = j;
            }
        }

        //Swapping 
        swap(arr[i],arr[minIndex]);
    }

    //Printing
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}