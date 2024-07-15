#include<iostream>
#include<vector>
using namespace std;

int KnapSackSolverRecursion(int n, int capacity, vector<int>&weight, vector<int>&values){
    if(n == 0){
        if(weight[0] <= capacity)
            return values[0];
        else    
            return 0;
    }
    int include = 0;
    if(weight[n] <= capacity){
        include = values[n] + KnapSackSolverRecursion(n-1, capacity - weight[n], weight, values);
    } 
    int exclude = 0 + KnapSackSolverRecursion(n-1, capacity, weight, values);
    int ans = max(include,exclude);
    return ans;
}

int KnapSackSolverTopDownDP(int n, int capacity, vector<int>&weight, vector<int>&values, vector<vector<int>>&dp){
    if(n == 0){
        if(weight[n] <= capacity)
            return values[n];
        else
            return 0;
    }
    if(dp[n][capacity] != -1){
        return dp[n][capacity];
    }
    int include = 0;
    if(weight[n] <= capacity)
        include = values[n] + KnapSackSolverTopDownDP(n-1,capacity-weight[n],weight,values,dp);
    int exclude = 0 + KnapSackSolverTopDownDP(n-1,capacity,weight,values,dp);
    dp[n][capacity] = max(include,exclude);
    return dp[n][capacity];
}

int KnapSack_BottomUpDP(int n, int capacity, vector<int>&weights, vector<int>&values){
    vector<vector<int>> dp(n,vector<int>(capacity+1, 0));
    for(int i = weights[0]; i <= capacity; i++){
        if(weights[0] <= capacity)
            dp[0][i] = values[0];
        else    
            dp[0][i] = 0;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= capacity; j++){
            int include = 0;
            if(weights[i] <= j){
                include = values[i] + dp[i-1][j - weights[i]];
            }
            int exclude = 0 + dp[i-1][j];
            dp[i][j] = max(include,exclude);
        }
    }
    return dp[n-1][capacity];
}

int Knapsack_SpaceOptimized(int n, int k,  vector<int>&weights, vector<int>&values){
    vector<int> prev(k+1,0);
    vector<int> curr(k+1,0);
    for(int i = weights[0]; i <= k; i++){
        if(weights[0] <= k)
            prev[i] = values[0];
        else    
            prev[i] = 0;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= k; j++){
            int include = 0;
            if(weights[i] <= j)
                include = values[i] + prev[j-weights[i]];
            int exclude = 0 + prev[j];

            curr[j] = max(include,exclude);
        }
        // Yaha galti hogi
        prev = curr;
    }
    return prev[k];
}

int main(){
    int n = 3;
    vector<int> weight = {4,5,1};
    vector<int> values = {1,2,3};
    int capacity = 4;
    // int ans = KnapSackSolverRecursion(n-1,capacity,weight,values);
    // cout << "Maximum Value of the knapsack: " << ans << endl;
    // vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
    // int a = KnapSackSolverTopDownDP(n-1, capacity, weight, values,dp);
    // cout << "Maximum Value of the knapsack: " << a << endl;
    int b = KnapSack_BottomUpDP(n,capacity,weight,values);
    cout << "Maximum Value of the knapsack: " << b << endl;

    int c = Knapsack_SpaceOptimized(n,capacity,weight,values);
    cout << "Maximum Value of the knapsack: " << c << endl;
    return 0;
}