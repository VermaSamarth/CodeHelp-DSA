#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

bool checkNums(vector<int> arr, int num2){
    int num = 0;
    for(auto it:arr)
        num = num * 10 + it;
    if(num > num2){
        cout << num << endl;
        return true;
    }
    return false;
}

int main(){
    int num1, num2, count = 0;
    cin >> num1 >> num2;
    vector<int> arr;
    for(int it = num1; it > 0; it/=10){
        arr.push_back(it%10);
    }
    for(int i = num2; i > 0; i/=10)
        count++;
    int num = num2 / pow(10,count);
    sort(arr.begin(),arr.end());
    auto it = find(arr.begin(),arr.end(), num);
    for(int it = 0; it < arr.size(); it++){
        swap(arr[0], arr[it]);
        if(checkNums(arr,num2)){
            count = -1;
            break;
            }
    }
    if(count != -1)     cout << -1 << endl;
}