#include<iostream>
#include<vector>
using namespace std;

int getMini(vector<int>& a, int k){
    // Base Case
    if(k == 0){
        return 0;
    }

    // Base Case
    if(k < 0){
        return INT_MAX;
    }

    // Decalare mini as INT_MAX
    int mini = INT_MAX;
    for(int i = 0; i < a.size(); i++){
        int ans = getMini(a,k-a[i]);
        if(ans != INT_MAX)
        mini = min(ans+1,mini);
    }
    return mini;
}

int main(){
    vector<int> arr = {1,2,4};
    int key = 9;
    int ans = getMini(arr,key);
    cout << ans << endl;
}