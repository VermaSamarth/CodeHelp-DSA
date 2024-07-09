#include<iostream>
#include<vector>
using namespace std;

// Recusive Solution
int PaintFenceRecursion(int n, int k){
    if(n == 1)
        return k;
    if(n == 2)
        return k * k;
    return (PaintFenceRecursion(n-1, k) + PaintFenceRecursion(n - 2, k)) * (k - 1);
}

// Top Down Dynamic Programming Solution
int PaintFenceTopDownDP(int n, int k, vector<int>dp){
    if(n == 1)
        return k;
    if(n == 2)
        return k*k;
    // Checking of the solution already existes in the DP Array
    if(dp[n] != -1)
        return dp[n];
    // storing the data in the DP Array
    dp[n] = (PaintFenceTopDownDP(n-1, k, dp) + PaintFenceTopDownDP(n-2, k, dp)) * (k-1);
    return dp[n];
}

// Tabulation or Bottom Up Dynamic Programming
int PaintFenceBottomUpDP(int n, int k){
    // create the DP Array
    vector<int> dp(n+1, 0);
    dp[1] = k;
    dp[2] = k * k;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) * (k-1);
    }
    return dp[n];
}

// Space Optimization Method
int PaintFenceSpaceOptimized(int n, int k){
    int num1 = k;
    
    int num2 = k * k;
    int num;
    for(int i = 3; i <= n; i++){
        num = (num1 + num2) * (k-1);
        num1 = num2;
        num2 = num;
    }
    return num2;
}

int main(){
    int n = 4;
    int k = 3;
    // using recursion
    // int ans = PaintFenceRecursion(n, k);
    // cout << "Recusion Answer: " << ans << endl;

    // using Top Down Dynamic programming
    vector<int> dp(n+1,-1);     // Creating the DP Array
    int a = PaintFenceTopDownDP(n, k, dp);
    cout << "TopDown DP Answer: " << a << endl;

    // using Bottom Up Dynamic Programming
    int ans = PaintFenceBottomUpDP(n,k);
    cout << "BottomUp DP Answer: " << ans << endl;

    // using Space optimized Dynamic Programming
    int b = PaintFenceSpaceOptimized(n,k);
    cout << "BottomUp DP Answer: " << b << endl;


}