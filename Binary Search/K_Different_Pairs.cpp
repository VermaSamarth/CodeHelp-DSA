#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int DifferentPairs(vector<int>&a, int k){
    // Making the set to store the pairs 
    set<pair<int,int>> pairs;
    if(a.size() < 2)
        return 0;
    int low = 0, high = 1; 
    while(low < a.size() && high < a.size()){
        if(low == high){
            high++;
        }
        if((a[high] - a[low]) == k){
            pairs.insert(make_pair(a[low], a[high]));
            cout << a[low] << " " << a[high] << endl;
            high++;
            low++;
        }
        else if((a[high] - a[low]) > k){
            low++;
        }
        else   
            high++;
    }
    return pairs.size();
}

int main(){
    vector<int> a = {3,1,4,1,5};        // -> {1,1,3,4,5}
    int k = 2;
    sort(a.begin(), a.end());
    int ans =  DifferentPairs(a,k);
    cout << "No. of Pairs with K sum = " << ans << endl;
}