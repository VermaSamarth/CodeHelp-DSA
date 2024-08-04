#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool CheckCycles(vector<int>list[], vector<int>&visited, queue<pair<int,int>>&que, int&n, int&src){
    visited[src] = 1;
    que.push(make_pair(src,-1));
    while(!que.empty()){
        int node = que.front().first;
        int parent = que.front().second;
        que.pop();
        for(auto index : list[node]){
            if(!visited[index]){
                que.push(make_pair(index, node));
                visited[index] = 1;
            }
            else if(parent != index){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n, m;
    cout << "Enter the number of nodes and edges: " << endl;
    cin >> n >> m;
    vector<int> list[n];
    for(int i = 0; i < m; i++){
        int u, v;
        cout << "Enter the nodes which has a edge between it." << endl;
        cin >> u >> v;
        // For Undirected graph
        list[u].push_back(v);
        list[v].push_back(u);
    }
    vector<int>visited(n,0);
    queue<pair<int,int>> que;
    bool ans = true;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            ans = ans & CheckCycles(list, visited, que, n, i);
            if(ans){
                cout << "Cyclic Graph." << endl;
                break;
            }
        }
    }
    if(!ans)    cout << "Not Cyclic Graph." << endl;
}