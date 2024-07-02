#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool PrataCookPossible(vector<int> r, int n, int p, int mid){
    int prata_count = 0;
    for(int i = 0; i < n; i++){
        int rank = r[i];
        int mul = 1;
        int time_taken = 0;
        while(true){
            if((time_taken + (mul * rank)) <= mid){
                prata_count++;
                time_taken = time_taken + (mul * rank);
                mul++;
            }
            else
                break;
        }
    }
    if(prata_count >= p)
        return true;
    else
        return false;
}

int Prata_Spoj(vector<int> r, int n, int p){
    sort(r.begin(), r.end());
    int start = 0;
    int highest = r[n-1];
    int end = highest * (p * (p+1))/2;
    int ans = -1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(PrataCookPossible(r,n,p,mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    // Number of Test Cases
    while(t--){
        // Number of cooks and pratas
        int n, p;
        cin >> p >> n;
        vector<int> r;
        int i = 0;
        // Rank of all the cooks
        while(i < n){
            int rank;
            cin >> rank;
            r.push_back(rank);
            i++;
        }
        cout <<  Prata_Spoj(r,n,p) << endl;
    }
}