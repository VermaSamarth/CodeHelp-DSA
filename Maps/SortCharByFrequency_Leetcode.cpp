#include<iostream>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    string str = "ababacdcdekfghs";
    string ansstr = "";
    // Map to find the count for the occurence of each character.
    map<char,int> mp;
    // Priority queue to store the data in the stored order.
    // Data stored in the priority queue is in the form of the pairs.
    priority_queue<pair<int,char>> nums;
    // Storing the occurence of each character and counter in the map.
    for(int i = 0; i < str.length(); i++){
        mp[str[i]]++;
    }
    // Sending the values of the map to priority queue.
    for(auto& it : mp)
        nums.push(make_pair(it.second,it.first));

    // Popping the queue elements and generating the new string.
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