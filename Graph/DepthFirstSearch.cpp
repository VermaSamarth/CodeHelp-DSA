#include<iostream>
#include<vector>
using namespace std;

void DepthFirstSearch(int&node, vector<int>&ans, vector<int>&visited, vector<int>list[]){
    visited[node] = 1;
    ans.push_back(node);
    for(auto it: list[node]){
        if(!visited[node]){
            DepthFirstSearch(it, ans, visited, list);
        }
    }
    return;
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
    vector<int>visited(n+1, 0);
    vector<int> ans;
    int node = 1;
    DepthFirstSearch(node, ans, visited, list);
    cout << ans.size() << endl;
    cout << "DFS of the Graph: ";
    for(auto it: ans){
        cout << it <<  " ";
    }
    cout << endl;
}


// Space Complexity = O(N)
// Time Complexity = O(N) + O(2*E)
// where N -> Number of nodes & E -> Number of edges