#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>arr = {3,2,1,7,5,4,9,6,8};
    int n = arr.size();
    int largest = INT_MIN;
    int smallest = INT_MAX;
    // Finding largest on even index
    for(int i = 0; i < n; i+=2){
        largest = max(largest, arr[i]);
    }
    // Finding smallest on odd index
    for(int i = 1; i < n; i+=2){
        smallest = min(smallest, arr[i]);
    }

    int sec_large = INT_MIN;
    int sec_small = INT_MAX;
    // Finding second largest on even index
    for(int i = 0; i < n; i+=2){
        if(arr[i] > sec_large && arr[i] < largest)
            sec_large = arr[i];
    }
    // Finding second smallest on odd index
    for(int i = 1; i < n; i+=2){
        if(arr[i] < sec_small && arr[i] > smallest)
            sec_small = arr[i];
    }
    cout << "Sum = " << sec_large + sec_small << endl;
}