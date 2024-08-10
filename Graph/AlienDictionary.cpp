#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void TopoSort(vector<int> adj[], vector<int> &visited, stack<int> &stk, int &node){
    visited[node] = 1;
    for (auto it : adj[node]){
        if (visited[it] == 0)
            TopoSort(adj, visited, stk, it);
    }
    stk.push(node);
    return;
}
string findOrder(string dict[], int N, int K){
    // code here
    vector<int> adj[K];
    vector<int> visited(K, 0);
    stack<int> stk;
    // Making the adjacency list
    for (int i = 0; i < N - 1; i++){
        string str1 = dict[i];
        string str2 = dict[i + 1];
        // Calculating the length of the smaller string
        int len = min(str1.length(), str2.length());
        for (int j = 0; j < len; j++){
            // Checking if the two alphabets of the string are equal or not?
            if (str1[j] != str2[j]){
                // Why - 'a'?
                // To store the integer value associated with the alphabet
                adj[str1[j] - 'a'].push_back(str2[j] - 'a');
                break;
            }
        }
    }
    for (int i = 0; i < K; i++){
        if (visited[i] == 0){
            TopoSort(adj, visited, stk, i);
        }
    }
    string ans = "";
    while (!stk.empty()){
        char chr = char(stk.top() + 65);
        ans.push_back(tolower(chr));
        stk.pop();
    }
    // cout << ans<< endl;
    return ans;
}

int main(){
    // List of strings of dictionary
}