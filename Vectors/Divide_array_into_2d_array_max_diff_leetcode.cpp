#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> divideArray(vector<int> &nums, int k){
    int count = 0;
    vector<vector<int>> ans_arr;
     
    for (int i = 0; i < nums.size() - 2; ++i) {
        int m = i;
        int n = i + 1;
        int o = i + 2;
        if ((nums[n] - nums[m] <= k) && (nums[o] - nums[n] <= k) && (nums[o] - nums[m] <= k)) {
            count = count + 3;
            vector<int> new_arr {nums[m], nums[n], nums[o]};
            ans_arr.emplace_back(new_arr);
            ++i;
            ++i;
        }
    }
    if (count == nums.size())
        return ans_arr;
    else {
        vector<vector<int>> empty_ans;
        return empty_ans;
    } 
}

void print2DArray(vector<vector<int>> &ans){
    cout << "Printing the resultant 2D array: " << endl;
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j <  3; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    int k = 2;
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans = divideArray(nums,k);
    print2DArray(ans);
}