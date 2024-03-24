#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {0,1,0,0,1,1,1,0,0,1};
    int len = arr.size();
    int zero = 0;
    int one  = 0;
    for(int i = 0; i < len; i++){
        if(arr[i] == 0)
            zero++;
        else    
            one++;
    } 
    arr.erase(arr.begin(),arr.end());
    for(int i = 0 ; i < zero; i++)
        arr.push_back(0);
    for(int i = 0 ; i < one; i++)
        arr.push_back(1);
    for(auto it:arr)
        cout << it << " ";
    cout << endl;
}