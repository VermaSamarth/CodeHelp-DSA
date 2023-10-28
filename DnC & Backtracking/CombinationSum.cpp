/*
 * Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. 
 * You may return the combinations in any order.
 * The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
 * The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
 * Example: 
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 */

#include<iostream>
#include<vector>
using namespace std;

int findSum(vector<int>& output){
    int sum = 0;
    for(int i = 0; i < output.size(); i++){
        sum = sum + output[i];
    }
    return sum;
}

void solve(int& len, int index, int& target, vector<int>& nums, vector<int>& output, vector<vector<int>>& ans){
    // Base Conditions
    if(findSum(output) == target){
        ans.push_back(output);
        return;
    }
    if(findSum(output) > target){
        return;
    }
    // Recursive Calls
    for(int i = index; i < nums.size(); i++){
        output.push_back(nums[i]);
        solve(len,index,target,nums,output,ans);
        output.pop_back();
        index++;
    }
}

int main(){
    vector<int> nums = {2,3,5,7};
    int target = 10;
    cout << "Given Target : " << target << endl;
    int len = nums.size();
    int index = 0;
    vector<int> output;
    vector<vector<int>> ans;
    solve(len,index,target,nums,output,ans);
    // Printing the answers
    cout << "Combinations that equals the sum are: " << endl;
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}