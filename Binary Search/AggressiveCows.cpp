#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsPossiblePlace(vector<int>&a, int&n, int&k, int&mid){
    int count = 1;
    int pos = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] - pos >= mid){
            count++;
            pos = a[i];
        }
        if(count == k)
            return true;
    }
    return false;
}

int main(){
    vector<int> a = {10,1,2,7,5};
    int n = 5, k = 3;
    sort(a.begin(), a.end());
    int start = 0;
    int end = a[n-1] - 1;
    int ans = -1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(IsPossiblePlace(a, n, k, mid)){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    cout << "Ans = " << ans << endl;
}