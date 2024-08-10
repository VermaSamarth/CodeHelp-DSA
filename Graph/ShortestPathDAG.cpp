#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void TopoSort(vector<pair<int, int>> adj[], vector<int> &visited, stack<int> &stk, int &node){
    visited[node] = 1;
    for (auto it : adj[node]){
        int n = it.first;
        if (visited[n] == 0)
            TopoSort(adj, visited, stk, n);
    }
    stk.push(node);
    return;
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges){
    // code here
    vector<pair<int, int>> adj[N];
    stack<int> stk;
    vector<int> distance(N, 1e9);
    vector<int> visited(N, 0);
    for (int i = 0; i < M; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back(make_pair(v, w));
    }
    for (int i = 0; i < N; i++){
        if (visited[i] == 0)
            TopoSort(adj, visited, stk, i);
    }
    distance[0] = 0;
    while (!stk.empty()){
        int topNode = stk.top();
        stk.pop();
        int dist = distance[topNode];
        for (auto it : adj[topNode]){
            int node = it.first;
            int curr = dist + it.second;
            distance[node] = min(distance[node], curr);
        }
    }
    for (int i = 0; i < N; i++){
        if (distance[i] == 1e9)
            distance[i] = -1;
    }
    return distance;
}

int main(){
    // Create the 2d vectors of edges
    
}