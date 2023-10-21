#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& a, int start, int end){
    int mid = (start + end) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;
    vector<int> left;
    vector<int> right;
    vector<int> mergeArr;
    int k = start;

    // Inserting the elements into the left sub array.
    for(int i = 0; i < len1; i++){
        left.push_back(a[k]);
        k++;
    }
    
    k = mid + 1;
    // Inserting the elements into the right sub array.
    for(int j = 0; j < len2; j++){
        right.push_back(a[k]);
        k++;
    }
    int m = 0, n = 0;
    while(m < len1 && n < len2){
        if(left[m] < right[n]){
            mergeArr.push_back(left[m]);
            m++;
        }
        else{
            mergeArr.push_back(right[n]);
            n++;
        }
    }
    if(m > len1){
        for(int i = n; i < len2; i++)
            mergeArr.push_back(right[i]);
    }
    else{
        for(int i = m; i < len1; i++)
            mergeArr.push_back(left[i]);
    }
    a.clear();
}

void mergeSort(vector<int>& arr, int start, int end){
    if(start >= end)
        return;
    int mid = (start + end) / 2;
    return mergeSort(arr, start, mid);
    return mergeSort(arr, mid + 1, end);
    return merge(arr, start, end);
}



int main(){
    vector<int> arr = {38,27,43,3,9,20};
    int len = arr.size();
    int start = 0;
    int end = len - 1;
    mergeSort(arr, start, end);
}