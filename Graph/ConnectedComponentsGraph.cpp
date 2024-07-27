#include<iostream>
#include<vector>
using namespace std;

void Traversal(int&i, vector<int>* list, vector<int>&visited){
    for(auto it: list[i]){
        visited[it] = 1;
    }
    return;
}

void PrintVisited(vector<int>&visited){
    cout << "Nodes Visited = ";
    for(int i = 0; i < visited.size(); i++){
        cout << visited[i] << " ";
    }
    cout << endl;
}

int main(){
    int n, m;
    cout << "Enter the number of nodes and edges: " << endl;
    cin >> n >> m;
    vector<int>list[n+1];
    for(int i = 0; i < m; i++){
        int u, v;
        cout << "Enter the nodes which have a edge between them: " << endl;
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    vector<int> visited(n+1,0);
    visited[1] = 1;
    for(int i = 1; i <= n; i++){
        cout << "Node =" << i << endl;
        if(!visited[i]){
            Traversal(i,list,visited);
            PrintVisited(visited);
        }
    }
}