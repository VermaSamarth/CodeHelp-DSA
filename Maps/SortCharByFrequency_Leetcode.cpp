#include<iostream>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    string str = "ababacdcdekfghs";
    string ansstr = "";
    priority_queue<pair<int,char>> nums;
    map<char,int> mp;
    for(int i = 0; i < str.length(); i++){
        mp[str[i]]++;
    }
    for(auto& it : mp)
        nums.push(make_pair(it.second,it.first));

    while(!nums.empty()){
        int size = nums.top().first;
        while(size != 0){
            ansstr.push_back(nums.top().second);
            size--;
        }
        nums.pop();
    }
    cout << "Original String: " << str << endl;
    cout << "Sorted String: " << ansstr << endl;
}