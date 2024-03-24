#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int start, int end){
    vector<int> left;
    vector<int> right;
    int mid = (start + end) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;
    
    // Copying elements into the left and right array.
    int k = start;
    for(int i = 0; i < len1; i++)
        left.push_back(arr[k++]);
    k = mid + 1;
    for(int i = 0; i < len2; i++)
        right.push_back(arr[k++]);
    
    // Merging the two arrays
    int i = 0, j = 0;
    k = start;
    while(i < len1 && j < len2){
        if(left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while(i < len1)
        arr[k++] = left[i++];
    while(j < len2)
        arr[k++] = right[j++];
    return;
}

void mergeSort(vector<int>& arr, int start, int end){
    if(start >= end)
        return;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end);
}

int main(){
    vector<int> arr = {40,30,40,90,80,60,50,10,20,70,80};
    int len = arr.size();
    int start = 0;
    int end = len - 1;
    mergeSort(arr,start,end);
    for(int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}