#include<iostream>
#include<vector>
using namespace std;

void subarrays(vector<int>& arr, int start, int end){
    if(end >= arr.size()){
        start++;
        end = start;
    }
    if(start >= arr.size()){
        return;
    }
    for(int i = start; i <= end; i++){
        cout << arr[i];
    }
    cout << endl;
    return subarrays(arr,start,end+1);
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    int len = arr.size();
    int end = 0;
    int start = 0;
    cout << "Printing the subarrays: " << endl;
    subarrays(arr,start,end);
}