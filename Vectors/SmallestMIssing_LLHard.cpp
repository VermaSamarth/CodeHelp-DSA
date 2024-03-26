#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
        int smallest_positive = INT_MAX;
        for(auto it:nums){
            if(smallest_positive > it && it > 0){
                smallest_positive = it;
            }
        }
        cout << "Smallest found positive: " << smallest_positive << endl;
        if(smallest_positive > 1)
            return 1;
        for(auto it: nums){
            cout << smallest_positive << " ";
            if(find(nums.begin(),nums.end(),smallest_positive) == nums.end())
                return smallest_positive;
            smallest_positive++;
        }
        cout << endl;
        return smallest_positive;
    }

int main(){
    vector<int> nums = {0,1,2};
    int ans = firstMissingPositive(nums);
    cout << "Ans: " << ans << endl;
}