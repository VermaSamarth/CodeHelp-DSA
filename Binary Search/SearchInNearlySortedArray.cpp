#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>arr,int target){
    int e = size(arr)-1;
    int s = 0;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(arr[mid]==target)
            return mid;
        else if(mid-1>=s && arr[mid-1]==target)
            return mid-1;
        else if(mid+1 <= e && arr[mid+1]==target)
            return mid;
        else if(target<arr[mid])
            e = mid - 2;
        else
            s = mid + 2;
        mid = s +(e-s)/2;
    }
    return -1;
}

int main(){
    vector<int> arr {10,3,40,20,50,80,70};
    int target = 10;
    int ans = binarySearch(arr, target);
    cout<<"Index of "<<target<<" is "<<ans<<endl;
    return 0;
}