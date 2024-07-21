#include<iostream>
#include<vector>
using namespace std;

long long int FindMaxSubsetProduct(vector<int>&arr, int&n){
    long long int mod = 1e9+7;
    long long int ans = 1;
    int count_zero = 0, count_neg = 0, mini = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            count_zero++;
            continue;
        }
        if(arr[i] < 0){
            mini = max(mini, arr[i]);
            count_neg++;
        } 
        ans = (ans * arr[i]) % mod;
    }
    if(count_zero == n) return 0;
    if(count_neg&1){
        if(count_neg == 1 && count_zero < n && (count_zero+count_neg == n))
            return 0;
        ans = ans / mini;
    }
    return ans;
}

int main(){
    vector<int> arr = {-1,-2,-1,0,2,1,4,5,-4,4,-9};
    int n = arr.size();
    cout << "Maximum Product Subset of the array = " << FindMaxSubsetProduct(arr,n) << endl;
}   