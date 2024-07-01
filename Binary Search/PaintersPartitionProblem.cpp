#include <iostream>
#include <vector>
using namespace std;

bool IsPaintingPossible(vector<int>&a, int&n, int&m, int&mid){
    int painter_count = 1, board_sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > mid)
            return false;
        if(board_sum + a[i] <= mid){
            board_sum += a[i];
        }
        else{
            painter_count++;
            board_sum = a[i];
            if(painter_count > m)
                return false;
        }
    }
    return true;
}

int PainterPartition(vector<int>&a, int&n, int&k){
    int start = 0;
    int end = 0;
    int ans = -1;
    for(int i = 0; i < n; i++){
        end += a[i];
    }
    while(start <= end){
        int mid = start + (end - start)/2;
        if(IsPaintingPossible(a,n,k,mid)){
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
    vector<int>a = {5,10,30,20,15};
    int n = 5, k = 3;
    int ans = PainterPartition(a, n, k);
    cout << "Minimum time needed to finish painting = " << ans << endl;
}