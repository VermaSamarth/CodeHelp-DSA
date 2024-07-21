#include<iostream>
#include<vector>
using namespace std;

int LIS_Recursion(vector<int>&arr, int prev, int curr){
    if(curr >= arr.size())
        return 0;
    int include = 0; 
    if(prev == -1 || arr[curr] > arr[prev])
        include = 1 + LIS_Recursion(arr, curr, curr+1);
    int exclude = 0 + LIS_Recursion(arr, prev, curr+1);
    int ans = max(include, exclude);
    return ans;
}

int LIS_Memoization(vector<int>&arr, int prev, int curr, vector<vector<int>>&dp){
    if(curr >= arr.size())
        return 0;
    if(dp[prev+1][curr] != -1)
        return dp[prev+1][curr];
    int include = 0;
    if(prev == -1 || arr[curr] > arr[prev])
        include = 1 + LIS_Memoization(arr, curr, curr+1,dp);
    int exclude = 0 + LIS_Memoization(arr, prev, curr+1,dp);
    dp[prev+1][curr] = max(include, exclude);
    return dp[prev+1][curr];
}

int LIS_Tabulation(vector<int>&arr){
    int n = arr.size();
    vector<vector<int>>dp(n+1, vector<int>(n+1,0));
    for(int curr = n-1; curr >= 0; curr--){
        for(int prev = curr-1; prev >= -1; prev--){
            int include = 0;
            if(prev == -1 || arr[curr] > arr[prev])
                include = 1 + dp[curr+1][curr+1];
            int exclude = 0 + dp[prev+1][curr+1];
            dp[prev+1][curr] = max(include, exclude);
        }
    }
    return dp[-1+1][0];
}

int LIS_OptimalSolution(vector<int>&arr){
    if(arr.size() == 0)
        return 0;
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > ans.back()){
            ans.push_back(arr[i]);
        }
        else{
            int index = lower_bound(ans.begin(), ans.end(), arr[i])-ans.begin();
            ans[index] = arr[i];
        }
    }
    return ans.size();
}

int main(){
    vector<int> arr = {0, 1, 0, 3, 2, 3};
    int prev = -1;
    int curr = 0;
    int a = LIS_Recursion(arr, prev, curr);
    cout << "Longest Increasing Subsequence = " << a << endl;

    int n = arr.size();
    vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
    int b = LIS_Memoization(arr, prev, curr, dp);
    cout << "Longest Increasing Subsequence = " << b << endl;

    int c = LIS_Tabulation(arr);
    cout << "Longest Increasing Subsequence = " << c << endl;

    int d = LIS_OptimalSolution(arr);
    cout << "Longest Increasing Subsequence = " << d << endl;
}