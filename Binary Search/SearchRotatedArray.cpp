#include<iostream>
#include<vector>
using namespace std;

int SearchArray(vector<int>&arr, int &target){
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == target)
            return mid;

        // Checking if the left half is sorted or not
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target < arr[mid])
                high = mid - 1;
            else    
                low = mid + 1;
        }
        // Checking if the right half is sorted or not.
        else{
            if(arr[mid] < target && target <= arr[high])
                low = mid + 1;
            else    
                high = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {4,5,6,7,8,9,10,0,1,2,3};
    int target = 3;
    cout << "Index of target = " << SearchArray(arr, target) << endl;
}