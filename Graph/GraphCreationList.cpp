#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cout << "Enter the number of nodes and edges: " << endl;
    cin >> n >> m;
    vector<int> list[n+1];
    for(int i = 0; i < m; i++){
        int u, v;
        cout << "Enter the nodes which has a edge between it." << endl;
        cin >> u >> v;
        // For Undirected graph
        list[u].push_back(v);
        list[v].push_back(u);

        // For directed graph
        // list[u].push_back(v);
    }
    cout << "Adjacency List:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto node : list[i]) {
            cout << node << " ";
        }
        cout << endl;
    }
}

// Space Complexity = O(2*m)

// Incase of Weighted Graph, 
// we will store the weight with the corresponding edge in a pair.
// vector<pair<int,int>>list[n+1];