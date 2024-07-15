#include<iostream>
#include<vector>
using namespace std;

int DicesRollsRecursion(int n, int k, int target){
    if(n < 0)   return 0;
    if(n == 0 && target == 0)   return 1;
    if(n != 0 && target == 0)   return 0;
    if(n == 0 && target != 0)   return 0;
    int ans = 0;
    for(int i = 1; i <= k; i++){
        ans = ans + DicesRollsRecursion(n-1, k, target-i);
    }
    return ans;
}

int DicesRollMemoization(int n, int k, int target, vector<vector<int>>&dp){
    if(n == 0 && target == 0)   return 1;
    if(n == 0 && target != 0)   return 0;
    if(n != 0 && target == 0)   return 0;
    if(n < 0)   return 0;
    if(dp[n][target] != -1)
        return dp[n][target];
    int ans = 0;
    for(int i = 1; i <= k; i++){
        if(target-i >= 0)
            ans = ans + DicesRollMemoization(n-1,k,target-i,dp);
    }
    dp[n][target] = ans;
    return dp[n][target];
}

int DicesRollTabulation(int n, int k, int target){
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));    // DP already initialized with 0.
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= target; j++){
            int ans = 0;
            for(int m = 0; m <= k; m++){
                if(j - m >= 0)
                    ans = ans + dp[i-1][j-m];
            }
        dp[i][j] = ans;
        }
    }  
    return dp[n][target];
}

int DicesRollSpaceoptimization(int n, int k, int target){
    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);
    prev[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= target; j++){
            int ans = 0;
            for(int m = 0; m <= k; m++){
                if(j - m >= 0)
                    ans = ans + prev[j-m];
            }
            curr[j] = ans;
        }
        prev = curr;
    }  
    return prev[target];
}

int main(){
    int n = 2;
    int k = 6;
    int target = 7;
    int ans = DicesRollsRecursion(n,k,target);
    cout << "Number of dice rolls: " << ans << endl;

    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
    int a = DicesRollMemoization(n,k,target,dp);
    cout << "Number of dice rolls: " << a << endl;

    int b = DicesRollTabulation(n,k,target);
    cout << "Number of dice rolls: " << b << endl;

    int c = DicesRollSpaceoptimization(n,k,target);
    cout << "Number of dice rolls: " << c << endl;
}