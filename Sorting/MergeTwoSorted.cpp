#include<iostream>
#include<vector>
using namespace std;

vector<int> merge(vector<int>& arr1, int& len1, vector<int>& arr2, int& len2){
    vector<int> mergeArr;
    // Using two pointer approach to merge the array.
    int i = 0;
    int j = 0;
    while(i < len1 && j < len2){

        // If element of array 1 is less than element of array 2.
        if(arr1[i] < arr2[j]){
            // Insert it in the merged array.
            mergeArr.push_back(arr1[i]);
            i++;
        }

        // If element of array 2 is less than element of array 1.
        else{
            // Insert it in the merged array.
            mergeArr.push_back(arr2[j]);
            j++;
        }
    }

    // If array 1 is complete then insert all remaining elements of array 2 into the merged array.
    if(i >= len1){
        for(int k = j; k < len2; k++)
            mergeArr.push_back(arr2[k]);
    }
    // If array 2 is complete then insert all remaining elements of array 1 into the merged array.
    else{
        for(int k = i; k < len1; k++)
            mergeArr.push_back(arr1[k]);
    }
    return mergeArr;
}

int main(){
    vector<int> arr1 = {2, 4, 6};
    vector<int> arr2 = {3, 5, 7, 9, 11};
    vector<int> mergedArray;
    int len1 = arr1.size();
    int len2 = arr2.size();
    mergedArray = merge(arr1, len1, arr2, len2);
    cout << "Sorted Array: ";
    for(auto val : mergedArray)
        cout << val << " ";
    cout << endl;
}