#include<iostream>
#include<vector>
using namespace std;

void merge(int* arr, int start, int end){
    // Finding the middle index
    int mid = (start + end) / 2;

    // Finding the length of the arrays
    int leftLen = mid - start + 1;
    int rightLen = end - mid;

    // Creating the Left subarray
    int* left = new int[leftLen];

    // Creating the right subarray
    int* right = new int[rightLen];

    // Copy the values into the array
    // Left array copy
    int k = start;
    for(int i = 0; i < leftLen; i++){
        left[i] = arr[k];
        k++;
    }

    // Right Array copy
    k = mid + 1;
    for(int i = 0; i < rightLen; i++){
        right[i] = arr[k];
        k++;
    }

    // Merge Logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainIndex = start;
    
    while(leftIndex < leftLen && rightIndex < rightLen){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainIndex] = left[leftIndex];
            mainIndex++;
            leftIndex++;
        }
        else{
            arr[mainIndex] = right[rightIndex];
            mainIndex++;
            rightIndex++;
        }
    }
    
    // Copy Remaining elements
    while(leftIndex < leftLen){
        arr[mainIndex] = left[leftIndex];
        mainIndex++;
        leftIndex++;
    }

    while(rightIndex < rightLen){
        arr[mainIndex] = right[rightIndex];
        mainIndex++;
        rightIndex++;
    }
    // TODO: Delete left and right created array
}

void mergeSort(int* arr, int start, int end){
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
    merge(arr,start,end);
}

int main(){
    int arr[6] = {38,27,43,3,9,20};
    int len = 6;
    int start = 0;
    int end = len - 1;
    mergeSort(arr,start,end);
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;  
}