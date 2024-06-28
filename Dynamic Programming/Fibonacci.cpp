#include<iostream>
#include<vector>
using namespace std;

// Recursive Solution
int fibo(int num){
    if(num == 1 || num == 0)
        return num;
    int ans = fibo(num - 1) + fibo(num - 2);
    return ans;
}

// Top-down Dynamic Programming
int TopDownFibo(int num, vector<int> &dp){
    // Base Case
    if(num == 1 || num == 0)
        return num;
    // Step3: Check if the value is already stored in the DP Array
    if(dp[num] != -1)
        return dp[num]; 

    // Step2: Store the answer in the dp array 
    dp[num] = TopDownFibo(num - 1, dp) + TopDownFibo(num - 2, dp);
    return dp[num];
}

// Bottom-up Dynamic Programming
int BottomUpFibo(int num){
    // Step1: Create the DP array
    vector<int> dp(num + 1, -1);

    // Step2: Update the dp array based on the previous Base case
    dp[0] = 0;
    if(num == 0)
        return 0;
    dp[1] = 1;

    // Step3: Loop laga do 2 to Num tak
    for(int i = 2; i <= num; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[num];
}

int main(){
    // Solving the problem using Recursion
    int num = 5;
    cout << "Ans: " << fibo(num) << endl;


    // Solving the problem using Dynamic Programming - Top Down Approach

    // Step1: Create a DP Array
    vector<int> dp (num + 1, -1);
    int ans1 = TopDownFibo(num, dp);
    cout << "Top Down Ans: " << ans1 << endl;


    // Solving the problem using Dynamic Programming - Top Down Approach

    int ans2 = BottomUpFibo(num);
    cout << "Bottom Up Ans: " << ans2 << endl;
}