#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Using a mathematical logic i.e., if count of same numbers = 'n'
// Then the possible combinations -> n*(n-1)/2
int numIdenticalPairs(vector<int>& nums) {
    int len = nums.size();  
    int count = 1, total = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < len - 1; i++){
        if(nums[i] == nums[i+1]){
            count++;
        }
        else{
            total = total + (count * (count - 1)) / 2;
            count = 1;
        }
    }
    total = total + (count * (count - 1)) / 2;
    return total;
}  

int main(){
    vector<int> arr = {1,2,3,1,1,3};
    cout << "Processing has begun!!!! " << endl;
    int count = numIdenticalPairs(arr);
    cout << "Number of Good Pairs: " << count << endl;
}

