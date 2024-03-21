#include<iostream>
#include<vector>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = nums[i];
            if(sum == goal)
                count++;
            for(int j = i + 1; j < nums.size(); j++){
                sum += nums[j];
                if(sum == goal)
                    count++;
                if(sum > goal)
                    break;
            }
        }
        return count;
    }

int main(){
    vector<int> arr = {1,0,1,0,1};
    int goal = 2;
    cout << numSubarraysWithSum(arr,goal) << endl;;
}