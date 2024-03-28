#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<int> nums;
  	int data, k;
  	cin >> data;
  	while(data != -1){
    	nums.push_back(data);
      	cin >> data;
    }
	cin >> k;
  	cout << "Enter the kth value: " << endl;
  	sort(nums.begin(),nums.end());
    for(auto it:nums)
        cout << it << " ";
    cout << endl;
  	cout << "Smallest kth value " << nums[k - 1] << endl;
  	return 0;
}