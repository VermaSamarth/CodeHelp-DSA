#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int>arr{10,1,7,6,14,9};
    sort(arr.begin(),arr.end());

    for(int i=0;i<arr.size();i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}