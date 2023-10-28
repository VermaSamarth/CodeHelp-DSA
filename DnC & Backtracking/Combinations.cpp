#include<iostream>
#include<vector>
using namespace std;
void solve(int& n, int& k, int levels, int start, vector<int>& output, vector<vector<int>>& ans){
    // Base Case
    if(levels >= k){
         ans.push_back(output);
         return;
    }

    for(int i = start; i <= n; i++){
        output.push_back(i);
        solve(n,k,levels+1,start+1,output,ans);
        output.pop_back();
        start++;
    }
    start++;
}

int main(){
    int n = 6, k = 3;
    vector<vector<int>> ans;
    vector<int> output;
    int levels = 0;
    int start = 1;
    solve(n,k,levels,start,output,ans);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}