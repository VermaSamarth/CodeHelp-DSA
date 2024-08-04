#include<iostream>
#include<vector>
using namespace std;
bool DFS_CycleDetection(int&node, int&parent, vector<int>list[], vector<int>&visited){
    visited[node] = 1;
    for(auto it: list[node]){
        if(!visited[it]){
            if(DFS_CycleDetection(it, node, list, visited))
                return true;
        }
        else if(parent != it)
            return true;
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
    bool ans = false;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            int parent = -1;
            ans = DFS_CycleDetection(i, parent, list, visited);
            if(ans){
                cout << "Cycle Detected. "<< endl;
                break;
            }
        }
    }
    if(!ans)
        cout << "Cycle not detected." << endl;
}