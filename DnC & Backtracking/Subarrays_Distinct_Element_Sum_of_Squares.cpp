#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

    // Function to count and return the number of distinct values inn the vector
    int Check(vector<int>& output){
        unordered_map<int,int> mapping;
    
        for(int i = 0; i < output.size(); i++){
            mapping[output[i]] = 1;
        }    
        int map_size = mapping.size();
        return map_size * map_size;
    }
    
    void solve(int& len, int start, int end, vector<int>& nums, vector<int> output, vector<int>& ans){
        // Base Conditions
        if(end >= nums.size()){
            start++;
            end = start;
        }
        if(start >= nums.size())
            return;
        
        // Inserting values into the vector
        for(int i = start; i <= end; i++){
            output.push_back(nums[i]);
        }
        
        // Updating the sum of distincts elements
        if(output.size() == 1)
            ans.push_back(1);
        else{
            // Counting the distinct elements using Check function
            int checkSize = Check(output);
            ans.push_back(checkSize);
        }
        
        // Popping/Emptying the vector
        for(int i = start; i <= end; i++){
            output.pop_back();
        }
        
        // Recursive calling the function
        solve(len, start, end + 1, nums, output, ans);
    }
    int sumCounts(vector<int>& nums) {
        int len = nums.size();
        int start = 0;
        int end = 0;
        int sum = 0;
        vector<int> ans;
        vector<int> output;
        solve(len, start, end, nums, output, ans);
        for(int i = 0; i < ans.size(); i++)
            sum = sum + ans[i];
        return sum;
    }
    int main(){
        vector<int> nums = {1,2,1};
        int sum = sumCounts(nums);
        cout <<"Sum : " << sum << endl;
    }