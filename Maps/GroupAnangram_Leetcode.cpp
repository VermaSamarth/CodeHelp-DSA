#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    unordered_map<string,vector<string>> store_str;
    vector<vector<string>> ans;
    vector<string> arr = {"eat","tea","tan","ate","nat","bat"};
    for(int  i = 0; i < arr.size(); i++){
        string str = arr[i];
        sort(arr[i].begin(),arr[i].end());
        store_str[arr[i]].push_back(str);
    }
    for(auto it = store_str.begin(); it != store_str.end(); it++){
        ans.push_back(it->second);
    }
    cout << "Group Anagrams: " << endl;
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}