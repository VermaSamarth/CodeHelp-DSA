#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

bool IsPossibleAllocation(vector<int> &a, int &n, int &m, int &mid){
    int page_sum = 0;
    int count = 1;
    for(int i = 0; i < n; i++){
        if(a[i] > mid)
            return false;
        if(a[i] + page_sum <= mid){
            page_sum = page_sum + a[i];
        }
        else{
            count++;
            page_sum = a[i];
            if(count > m)
                return false;
        }
    }
    return true;
}

int BookAllocation(vector<int> &a, int &n, int &m){
    int ans = -1;
    // If number of students greater than the number of books
    if(m > n)   
        return ans;
    
    int start = 0, end = accumulate(a.begin(), a.end(), 0);
    while(start <= end){
        int mid = (start + end)/2;
        if(IsPossibleAllocation(a, n, m, mid)){
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
    vector<int> a = {15,45,89,65,75,55,151,520,79,100};
    int n = 10;
    int m = 4;
    cout << "Minimum of maximum number of pages a student can get = " << BookAllocation(a, n, m) << endl;
}