#include<iostream>
#include<vector>
using namespace std;

// Partition Logic
int partition(int arr[],int start,int end){
    // Choose pivot element
    int pivotIndex = start;
    int pivotElement = arr[start];

    // Find right position for the pivot element.
    int count = 0;
    int iterator = start + 1;
    while(iterator <= end){
        if(arr[iterator++] <= pivotElement)
            count++;
    }

    // Now place the pivot element at its correct position.
    swap(arr[pivotIndex],arr[start + count]);
    pivotIndex = start + count;

    // Place Smaller elements on left and bigger elements on rght.
    int i = start;
    int j = end;

    while(i < pivotIndex && pivotIndex < j){
        while(arr[i] <= pivotElement)
            i++;
        while(arr[j] > pivotElement)
            j--;  

        // There is a possibility that left me larger and right me smaller elements ho.
        // Swap those elements: Upar ke dono while loop false hone pr agar index sahi honge then swap krdege else no swapping.
        if(i < pivotIndex && pivotIndex < j)
        swap(arr[i],arr[j]);
    }
    return pivotIndex;
}

// Quick Sort Logic
void quickSort(int arr[], int start, int end){
    // Base Case
    if(start >= end)
        return;
    
    // Partition Logic
    int pivot = partition(arr,start,end);

    // Recursive Call
    // Left of Pivot Element
    quickSort(arr,start,pivot - 1);

    // Rigth of Pivot Element
    quickSort(arr,pivot + 1,end);
}

int main(){
    int arr[] = {8,8,1,1,1,3,3,4,20,20,20,20,50,30};
    int len = 14;
    int start = 0;
    int end = len - 1;
    quickSort(arr,start,end);
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}