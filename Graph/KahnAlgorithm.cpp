#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) {
    // code here
    vector<int>indegree(V,0);
    queue<int>que;
    for(int i = 0; i < V; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }
    for(int i = 0; i < V; i++){
        if(indegree[i] == 0)
            que.push(i);
    }
    vector<int>ans;
    while(!que.empty()){
        int front = que.front();
        que.pop();
        ans.push_back(front);
        for(auto it: adj[front]){
            indegree[it]--;
            if(indegree[it] == 0)
                que.push(it);
        }
    }
    return ans;
}

main(){
    // To send the input i.e. adjacency list from here
}