#include<iostream>
#include<vector>
using namespace std;

// vector ko passing as Reference Varibale
int binarySearch(vector<int>& arr, int& key, int start, int end){
    // Agar start > end hogya matlab humme key nahi milli toh humne false return kardiya.
    if(start > end)
        return -1;
    // Calculating the middle index
    int mid = (start+end)/2;
    // Base Case
    if(arr[mid] == key)
        return mid;
    else if(arr[mid] < key)
        return binarySearch(arr,key,mid+1,end);
    else    
        return binarySearch(arr,key,start,mid-1);
}

int main(){
    vector<int> arr = {10,20,30,40,50,60,70,80,90};
    int len = sizeof(arr);
    int key = 10;
    int start = 0, end = sizeof(arr) - 1;
    int index = binarySearch(arr,key,start,end);
    cout << "Found at index: "<< index << endl;
}