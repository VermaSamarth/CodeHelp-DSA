#include <iostream>
#include <vector>
using namespace std;

// Using recursion -> Exponential Time Complexity
int CoinChange(vector<int>&coins, int target){
    if(target == 0)
        return 0;
    if(target < 0)
        return INT_MAX;
    int mini = INT_MAX;
    for(int i = 0; i < coins.size(); i++){
        int ans = CoinChange(coins, target - coins[i]);
        if(ans != INT_MAX)
            mini = min(mini, ans + 1);
    }
    return mini;
}

// Solve using top down Approach -> Time Complexity O(N) + O(N)
int TopDown_CoinChange(vector<int>&coins, int target, vector<int>&dp){
    if(target == 0)     
        return 0;
    if(target < 0)
        return INT_MAX;
    if(dp[target] != -1)
        return dp[target];
    int mini = INT_MAX;
    for(int i = 0; i < coins.size(); i++){
        int ans = TopDown_CoinChange(coins, target - coins[i], dp);
        if(ans != INT_MAX)
            mini = min (mini, ans + 1);
    }
    dp[target] = mini;  
    return dp[target];
}

// Solve using the bottom up Approach
int BottomUp_CoinChange(vector<int>& coins, int target){
    // Step1: Create the DP Array
    vector<int> dp(target + 1, -1);

    // Step2: Update the DP Array based on previous Base Case
    dp[0] = 0;

    // Step3: Check the range and flow of top down approach and node accordingly
    for(int i = 1; i <= target; i++){
        int mini = INT_MAX;
        for(int j = 0; j < coins.size(); j++){
            if(i - coins[j] >= 0){
                int ans = dp[i - coins[j]];
                if(ans != INT_MAX)
                    mini = min(mini, ans + 1);
            }
        }
        dp[i] = mini;
    }
    return dp[target];
}

int main(){
    vector<int> coins = {1, 2, 5};
    int target = 11;
    cout << "No. of coins needed = " << CoinChange(coins, target) << endl;

    vector<int> dp(target + 1, -1);
    int ans = TopDown_CoinChange(coins, target, dp);
    if(ans == INT_MAX)
        cout << "No. of coins needed = -1" << endl;
    else    
        cout << "No. of coins needed = " << ans << endl; 

    int soln = BottomUp_CoinChange(coins, target);
    if(soln == INT_MAX)
        cout << "No. of coins needed = -1" << endl;
    else    
        cout << "No. of coins needed = " << soln << endl;     
}