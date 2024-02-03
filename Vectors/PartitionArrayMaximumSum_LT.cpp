

// ******* Code is not right. Will be updated later. *******

#include <iostream>
#include <vector>
using namespace std;

vector<int> findMaximumSum(vector<int> &nums, int k){
    int currentMax = INT_MIN;
    for(int i = 0; i <= nums.size() - k; i = i + k){
        currentMax = INT_MIN;
        for(int j = i; j < i + k; j++){
            if(currentMax < nums[j]){
                currentMax = nums[j];
            }
        }
        for(int j = i; j < i + k; j++){
            nums[j] = currentMax;
        }
    }
    return nums;
}

int main(){
    vector<int> arr = {1,4,1,5,7,3,6,1,9,9,3};
    int k = 4;
    int sum = 0;
    cout << "Original Vectors: ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl << "Modified Vectors: ";
    vector<int> ans_arr = findMaximumSum(arr,k);
    for(int i = 0; i < ans_arr.size(); i++){
        cout << ans_arr[i] << " ";
        sum = sum + ans_arr[i];
    }
    cout << endl;
    cout << "Maximum Sum: " << sum << endl;
}