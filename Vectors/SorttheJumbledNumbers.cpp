#include<iostream>
#include<vector>
#include<map>
#include<math.h>
using namespace std;

vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    map<int, vector<int>> mp;
    for(auto num : nums) {
        int createdNum = 0;
        int n = 0;
        if (num == 0) {
            createdNum = mapping[0];
        } else {
            for (int i = num; i != 0; i /= 10) {
                int d = mapping[i % 10];
                createdNum = (d * (int)(pow(10, n++))) + createdNum;
            }
        }
        mp[createdNum].push_back(num);
    }

    vector<int> ans;
    for (auto it : mp) {
        for (int j = 0; j < it.second.size(); j++) {
            ans.push_back(it.second[j]);
        }
    }
    return ans;
}

int main(){
    vector<int> mapping = {8,9,4,0,2,1,3,5,7,6};
    vector<int> nums = {991,338,38};
    cout << "Given Order: ";
    for(auto it: nums){
        cout << it << " ";
    }
    cout << endl;
    vector<int> ans = sortJumbled(mapping,nums);
    cout << "Sorted Order: ";
    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
}