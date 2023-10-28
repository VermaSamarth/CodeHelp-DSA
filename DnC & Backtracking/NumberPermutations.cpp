// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
#include<iostream>
#include<vector>
using namespace std;

void solve(int& len, int index, vector<int>& nums, vector<vector<int>>& ans){
    // Base Condition
    if(index >= len){
        ans.push_back(nums);
        return;
    }

    // Recursive Calls
    for(int i = index; i < len; i++){
        swap(nums[i], nums[index]);
        solve(len,index+1,nums,ans);
        // Backtracking
        swap(nums[i],nums[index]);
    }
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> ans;
    int len = nums.size();
    int index = 0;
    solve(len,index,nums,ans);
    // Printing the found solutions
    cout << "Permutations : " << endl;
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}