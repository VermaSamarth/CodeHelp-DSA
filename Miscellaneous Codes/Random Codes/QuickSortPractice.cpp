#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int> arr, int start, int end){
    int pivot = arr[start];
    int pindex = start;
    int count = 0;
    for(int i = start + 1; i < arr.size(); i++){
        if(arr[i] <= pivot)
            count++;
    }
    swap(arr[pindex],arr[start+count]);
    pindex = start + count;
    pivot = arr[pindex];

    int i = start, j = end;
    while(i < pindex && j > pindex){
        while(arr[i] <= pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i < pindex && j > pindex)
            swap(arr[i],arr[j]);
    }
    return pindex;
}

void quickSort(vector<int> arr, int start, int end){
    // Base Condition
    if(start >= end)
        return;
    // Finding Pivot
    int pivot = findPivot(arr,start,end);
    quickSort(arr,start,pivot-1);
    quickSort(arr,pivot+1,end);
}

int main(){
    vector<int> arr = {60,70,10,20,100,50,30,80,40,90,60};
    int len = arr.size();
    int start = 0;
    int end = len - 1;
    cout << "Length: " << len << endl;
    quickSort(arr,start,end);
    for(int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}