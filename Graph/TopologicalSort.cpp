#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void DFS(int&i, vector<int>adj[], vector<int>&visited, stack<int>&stk){
        visited[i] = 1;
        for(auto it: adj[i]){
            if(!visited[it]){
                DFS(it, adj, visited, stk);
            }
        }
        stk.push(i);
        return;
    }  
//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) {
    // code here
   vector<int>visited(V,0);
    stack<int>stk;
    for(int i = 0; i < V; i++){
        if(visited[i] == 0){
            DFS(i, adj, visited, stk);
        }
    }
    vector<int>ans;
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}

int main(){
    // Input will come from the main.
}