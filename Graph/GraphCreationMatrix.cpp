#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cout << "Enter number of nodes and edges: " << endl;
    cin >> n >> m;
    // Storing the graph in the Vector
    vector<vector<int>>adj(n+1,vector<int>(m+1,0));
    for(int i = 0; i < m; i++){
        int u, v;
        cout << "Enter the two nodes which have a edge: " << endl;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    // Printing the adjacency matrix
    cout << "Printing the Adjacency Matrix: " << endl;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

// Space Complexity = O(n*m)
// In case of Weighted Graph,
// We will store the weight in adj[u][v], instead of 1.