#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long int IsCuttingPossible(vector<long long int>&trees, long long int&n, long long int&m, long long int&mid){
    long long int sum = 0;
    for(long long int i = 0; i < n; i++){
        if(trees[i] > mid){
            sum += trees[i] - mid;
        } 
    }
    if(sum >= m)    
        return sum;
    else
        return -1;
}

long long int EkoSpoj(vector<long long int>&trees, long long int&n, long long int&m){
    sort(trees.begin(), trees.end());
    long long int start = 0;
    long long int end = trees[n - 1];
    long long int ans = 0;
    while(start <= end){
        long long int mid = start + (end-start)/2;
        long long int cutlen = IsCuttingPossible(trees,n,m,mid);
        if(cutlen == -1){
            end = mid - 1;
        }
        else{
            ans = max(ans, mid);
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    long long int n, m, i = 0;
    cin >> n >> m;  
    vector<long long int> trees;  // 4 trees of different heights
    while(i < n){
        long long int inp;
        cin >> inp;
        trees.push_back(inp);
        i++;
    }
    long long int ans = EkoSpoj(trees, n, m);
    cout << "Maximum height of Chainsaw to cut minimum length: " << ans << endl;
}