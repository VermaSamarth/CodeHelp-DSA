#include<iostream>
#include<vector>
using namespace std;

int trappingwater(vector<int> rain){
    int left = 0;
    int right = rain.size();
    int left_max = INT_MIN;
    int right_max = INT_MIN;
    int ans = 0;
    while(left < right){
        left_max = max(rain[left],left_max);
        right_max = max(rain[right], right_max);
        ans += (left_max < right_max) ? left_max - rain[left++] : right_max - rain[right--];
    }
    return ans;
}

int main(){
    int data, num;
    cin >> num;
    vector<int> rain;
    for(int i = 0; i < num; i++){
        cin >> data;
        rain.push_back(data);
    }
    cout << "Trapped water = " << trappingwater(rain) << endl;
}
