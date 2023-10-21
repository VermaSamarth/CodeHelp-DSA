#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
int removeDuplicate(vector<int>& nums, int& len){
    int count = 1;
    for(int i = 1; i < len; i++){
        if(nums[i] == nums[i-1])
            nums[i-1] = INT_MAX;
        else
            count++;
    }
    sort(nums.begin(), nums.end());
    return count;
}

int main(){
    vector<int> nums = {0,0,1,1,2,2,2,2,3,3,4,5,5,5,6,7,9,9,10};
    int len = nums.size();
    cout << "Before removing duplicates: " ;
    for(auto val : nums)
        cout << val << " ";
    cout << endl;
    int count = removeDuplicate(nums, len);
    cout << "After removing duplicates: " ;
    for(int i = 0; i< count; i++)
        cout << nums[i] << " ";
    cout << endl;
}