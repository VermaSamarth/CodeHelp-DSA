#include<iostream>
#include<vector>
using namespace std;

int FindSubsequenceRecursion(string&text1, string&text2, int iterator1, int iterator2){
    if(iterator1 == text1.length() || iterator2 == text2.length())
        return 0;
    if(text1[iterator1] == text2[iterator2])
        return 1 + FindSubsequenceRecursion(text1, text2, iterator1+1, iterator2+1);
    else    
        return max(FindSubsequenceRecursion(text1, text2, iterator1+1, iterator2), FindSubsequenceRecursion(text1, text2, iterator1, iterator2+1));
}

int FindSubsequenceMemoization(string&text1, string&text2, int iterator1, int iterator2, vector<vector<int>>&dp){
    if(iterator1 == text1.length() || iterator2 == text2.length())
        return 0;
    if(dp[iterator1][iterator2] != -1)
        return dp[iterator1][iterator2];
    if(text1[iterator1] == text2[iterator2])
        dp[iterator1][iterator2] = 1 + FindSubsequenceMemoization(text1, text2, iterator1+1, iterator2+1, dp);
    else    
        dp[iterator1][iterator2] = max(FindSubsequenceMemoization(text1, text2, iterator1+1, iterator2, dp), FindSubsequenceMemoization(text1, text2, iterator1, iterator2+1, dp));
    return dp[iterator1][iterator2];
}

int FindSubsequenceTabulation(string&text1, string&text2){
    int n1 = text1.length();
    int n2 = text2.length();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    for(int i = n1-1; i >= 0; i--){
        for(int j = n2-1; j >= 0; j--){
            if(text1[i] == text2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    return dp[0][0];
}

int main(){
    string text1, text2;
    cin >> text1 >> text2;
    int iterator1 = 0, iterator2 = 0;
    int n1 = text1.length();
    int n2 = text2.length();
    int ans1 = FindSubsequenceRecursion(text1, text2, iterator1, iterator2);
    cout << "Length of the longest Common Subsequence = " << ans1 << endl;

    vector<vector<int>>dp(n1+1, vector<int>(n2+1,-1));
    int ans2 = FindSubsequenceMemoization(text1, text2, iterator1, iterator2, dp);
    cout << "Length of the longest Common Subsequence = " << ans2 << endl;

    int ans3 = FindSubsequenceTabulation(text1, text2);
    cout << "Length of the longest Common Subsequence = " << ans3 << endl;
}