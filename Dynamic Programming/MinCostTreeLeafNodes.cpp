#include<iostream>
#include<vector>
#include<map>
using namespace std;

int MinCostTreeRecursion(vector<int>&arr, map<pair<int,int>,int>&mp, int left, int right){
    if(left == right)   return 0;
    int ans = INT_MAX;
    for(int i = left; i < right; i++){
        ans = min(ans, (mp[{left,i}]*mp[{i+1,right}]) + MinCostTreeRecursion(arr,mp, left, i) + MinCostTreeRecursion(arr,mp,i+1,right));
    }
    return ans;
}

int MinCostTreeMemoization(vector<int>&arr, map<pair<int,int>,int>&mp, int left, int right, vector<vector<int>>&dp){
    if(left == right)   return 0;
    if(dp[left][right] != -1)
        return dp[left][right];
    int ans = INT_MAX;
    for(int i = left; i < right; i++){
        ans = min(ans, (mp[{left,i}]*mp[{i+1,right}]) + MinCostTreeMemoization(arr,mp, left, i, dp) + MinCostTreeMemoization(arr,mp,i+1,right, dp));
    }
    dp[left][right] = ans;
    return dp[left][right];
}

int MinCostTreeTabulation(vector<int>&arr, map<pair<int,int>,int>&mp){
    int n = arr.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int left = n - 1; left >= 0; left--){
        for(int right = 0; right < n; right++){
            if(left>=right)
                continue;
            else{
                int ans = INT_MAX;
                for(int i = left; i < right; i++){
                    ans = min(ans, (mp[{left,i}] * mp[{i+1,right}]) + dp[left][i] + dp[i+1][right]);
                }
                dp[left][right] = ans;
            }
        }
    }
    return dp[0][n-1];
}
int main(){
    vector<int> arr = {6,2,4};
    map<pair<int,int>,int>mp;
    for(int i = 0; i<arr.size(); i++){
        mp[{i,i}] = arr[i];
        for(int j = i+1; j<arr.size(); j++){
            mp[{i,j}] = max(arr[j], mp[{i,j-1}]);
        }
    }
    int n =arr.size();
    int a = MinCostTreeRecursion(arr,mp,0,n-1);
    cout << "Min Cost = " << a << endl;

    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    int b = MinCostTreeMemoization(arr,mp,0,n-1,dp);
    cout << "Min Cost = " << b << endl;

    int c = MinCostTreeTabulation(arr,mp);
    cout << "Min Cost = " << c << endl;
}