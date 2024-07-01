#include<iostream>
#include<vector>
#include<algorithm>
// #include<limits.h>
using namespace std;

int BinarySearch(vector<int>&a, int &x, int low, int high){
    while(low <= high){
        int mid = low + (high-low)/2;
        if(a[mid] == x)
            return mid;
        else if(a[mid] < x)
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1;
}

int ExponentionSearch(vector<int>&a, int &x){
    int n = a.size();
    if(a[0] == x)
        return 0;
    int i = 1;
    while(i < n && a[i] <= x){
        i = i *2;
        if(a[i] == x)   return i;   // Added by myself (Samarth Verma)
    }
    // int h = min(i, a.size()-1);
    return BinarySearch(a, x, i/2, min(i, n-1));
}

int main(){
    vector<int> a = {3,4,5,6,11,13,14,15,18,20,50};
    int x = 18;
    cout << "Ans: " << ExponentionSearch(a, x) << endl;
}