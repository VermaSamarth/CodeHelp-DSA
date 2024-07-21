#include<iostream>
#include<vector>
using namespace std;

int GuessNumberRecursion(int start, int end){
    if(start >= end)    return 0;
    int ans = INT_MAX;
    for(int i = start; i <= end; i++){
        ans = min(ans, i + max(GuessNumberRecursion(start,i-1), GuessNumberRecursion(i+1,end)));
    }
    return ans;
}

int GuessNumberMemoization(int start, int end, vector<vector<int>>&dp){
    if(start >= end)    return 0;
    if(dp[start][end]!=-1)  return dp[start][end];
    int ans = INT_MAX;
    for(int i = start; i <= end; i++){
        ans = min(ans, i + max(GuessNumberMemoization(start,i-1,dp),GuessNumberMemoization(i+1,end,dp)));
    }
    dp[start][end] = ans;
    return dp[start][end];
}

int GuessNumberTabulation(int n){
    vector<vector<int>>dp(n+2,vector<int>(n+1,0));
    for(int start = n; start >= 1; start--){
        for(int end = 1; end <= n; end++){
            if(start >= end)    continue;
            else{
                int ans = INT_MAX;
                for(int i = start; i <= end; i++){
                    ans = min(ans, i+max(dp[start][i-1], dp[i+1][end]));
                }
                dp[start][end] = ans;
            }
        }
    }
    return dp[1][n];
}

int main(){
    int n;
    cin >> n;
    int a = GuessNumberRecursion(1, n);
    cout << "Minimum amount to win regardless of guess: " << a << endl;

    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    int b = GuessNumberMemoization(1,n,dp);
    cout << "Minimum amount to win regardless of guess: " << b << endl;

    int c = GuessNumberTabulation(n);
    cout << "Minimum amount to win regardless of guess: " << c << endl;
}