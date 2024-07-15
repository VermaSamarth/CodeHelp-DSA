// Inclusion Exclusion Approach
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

bool RecursiveSubsetSum(vector<int>&arr, int target, int n){
    if(n == 0){
        if(target == 0) return true;
        return false;
    }
    if(target < 0)  return false;
    if(target == 0) return true;
    bool include = RecursiveSubsetSum(arr, target - arr[n], n - 1);
    bool exclude = RecursiveSubsetSum(arr, target, n - 1);
    return (include || exclude);
}

bool Memoization_SubsetSum(vector<int>&arr, int target, int n, vector<vector<int>>&dp){
    if(n == 0){
        if(target == 0) return 1;
        return 0;
    }
    if(target < 0)  return 0;
    if(target == 0) return 1;
    if(dp[n][target] != -1)
        return dp[n][target];
    bool include = Memoization_SubsetSum(arr, target - arr[n], n - 1, dp);
    bool exclude = Memoization_SubsetSum(arr, target, n - 1, dp);
    dp[n][target] = (include || exclude);
    return dp[n][target];
}

bool Tabulation_SubsetSum(vector<int>&arr, int target, int n){
    vector<vector<int>> dp(n+1, vector<int>(target+1,-1));
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = 1; j <= target; j++){
            bool include = 0;
            if(j - arr[i] >= 0)
                include = dp[i+1][j - arr[i]];
            bool exclude = dp[i+1][j];
            dp[i][j] = (include || exclude);
        }
    }
    return dp[0][target];
}

bool SpaceOptimization_SubsetSum(vector<int>&arr, int target, int n){
    vector<int> next(target+1, 0);
    vector<int> curr(target+1, 0);
    next[0] = 1;
    curr[0] = 1;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 1; j <= target; j++){
            bool include = 0;
            if(j - arr[i] >= 0)
                include = next[j-arr[i]];
            bool exclude = next[j];
            curr[j] = (include||exclude);
        }
        // curr = next;
        next = curr;
    }
    return curr[target];
}

int main(){
    vector<int> arr = {1,5,11,5};
    int total = accumulate(arr.begin(), arr.end(), 0);
    if(total & 1)
        cout << "Not Possible" << endl;
    else{
        int target = total/2;
        int n = arr.size() - 1;
        // bool ans = RecursiveSubsetSum(arr, target,n);

        // Memoization or TopDownDP Approach
        vector<vector<int>> dp(arr.size(), vector<int>(target+1,-1));
        bool ans = Memoization_SubsetSum(arr, target, n, dp);
        cout << "Possible: " << ans << endl;
        // Tabulation or BottomUpDp Approach
        bool a = Tabulation_SubsetSum(arr, target, n);
        cout << "Possible: " << a << endl;

        // Space Optimized DP Approach
        bool b = SpaceOptimization_SubsetSum(arr,target,n);
        cout << "Possible: " << b << endl;
    }
}