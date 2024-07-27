#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> BFS_Traversal(vector<int> list[], int&n){
    vector<int>visited(n+1, 0);
    vector<int> ans;
    queue<int> que;
    que.push(1);
    visited[1] = 1;
    while(!que.empty()){
        int node = que.front();
        for(auto it: list[node]){
            if(!visited[it]){
                visited[it] = 1;
                que.push(it);
            }
        }
        que.pop();
        ans.push_back(node);
    }
    return ans;
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
    vector<int> ans = BFS_Traversal(list, n);
    cout << "BFS Traversal of Graph: ";
    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
}