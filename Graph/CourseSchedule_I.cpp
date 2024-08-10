#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites){
    // Creating the Adjacency List
    vector<int> adj[numCourses];
    for (auto it : prerequisites){
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
    }
    // Creating the indegree list
    vector<int> indegree(numCourses, 0);
    for (int i = 0; i < numCourses; i++){
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    // Pushing the nodes with zero indegre into the queue
    queue<int> que;
    for (int i = 0; i < numCourses; i++){
        if (indegree[i] == 0)
            que.push(i);
    }
    // Finding the topological sort of the nodes
    int count = 0;
    while (!que.empty()){
        int front = que.front();
        que.pop();
        count++;
        for (auto it : adj[front]){
            indegree[it]--;
            if (indegree[it] == 0)
                que.push(it);
        }
    }
    if (count == numCourses)
        return true;
    return false;
}

int main(){
    
}