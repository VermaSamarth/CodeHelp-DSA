#include<iostream>
#include<vector>
using namespace std;

void findSum(vector<int>& arr, int ans, int& len, int i, int& maxi){
    if(i>=len){
        maxi = max(ans,maxi);
        return;
    }
    findSum(arr, ans + arr[i], len, i+2, maxi);
    findSum(arr, ans, len, i+1, maxi);
}

int main(){
    vector<int> arr = {2,1,4,9};
    int len = arr.size();
    int i = 0;
    int ans = 0;
    int maxi = INT_MIN;
    findSum(arr, ans, len, i, maxi);
    cout << "Maximum Sum: " << maxi << endl;
}