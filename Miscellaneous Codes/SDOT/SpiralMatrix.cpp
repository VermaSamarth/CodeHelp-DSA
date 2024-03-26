#include<iostream>
#include<vector>
using namespace std;

int main(){
    int row, col, data;
    cin >> row >> col;
    vector<vector<int>>nums(row);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> data;
            nums[i].push_back(data);
        }
    }

    int left = 0, right = col - 1, top = 0, bottom = row - 1;
    int total = row * col, count = 0;
    while(left <= right && top <= bottom){
        for(int i = left; i <= right && count < total; i++){
            cout << nums[top][i] << " ";
            count++;
        }
        top++;
        for(int i = top; i <= bottom && count < total; i++){
            cout << nums[i][right] << " ";
            count++;
        }
        right--;
        for(int i = right; i >= left && count < total; i--){
            cout << nums[bottom][i] << " ";
            count++;
        }
        bottom--;
        for(int i = bottom ; i >= top && count < total; i--){
            cout << nums[i][left] << " ";
            count++;
        }
        left++;
    }
}