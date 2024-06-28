#include<iostream>
#include<vector>
using namespace std;

bool SearchArray(vector<int>&arr, int &target){
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == target)
            return true;

        // Checking if the low & mid & high are same
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            // Shrinking the array size
                low++;
                high--;
        }
        // Checking if the left half is sorted or not
        else if(arr[low] <= arr[mid]){
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
    return false;
}

int main(){
    vector<int> arr = {4,5,6,7,8,9,10,0,1,2,3,4};
    int target = 3;
    cout << "Target Present? " << SearchArray(arr, target) << endl;
}