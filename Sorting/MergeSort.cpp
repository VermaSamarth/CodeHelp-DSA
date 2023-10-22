#include<iostream>
#include<vector>
using namespace std;

int mergeSort(int* arr, int start, int end){
    // Base Case
    // if start == end -> Single element -> Already Sorted
    // if start > end -> Invalid Array
    if(start >= end)
        return;

    // Divide the array into two parts
    int mid = (start + end) / 2;
    
    // Left Part divide and then Sort
    mergeSort(arr,start,mid);
    
    // Rigth Part divide and then Sort
    mergeSort(arr,mid+1,end);
    
    // Merge the sorted arrays
}

int main(){
    int arr[6] = {38,27,43,3,9,20};
    int len = 6;
    int start = 0;
    int end = len - 1;
    mergeSort(arr,start,end);
}