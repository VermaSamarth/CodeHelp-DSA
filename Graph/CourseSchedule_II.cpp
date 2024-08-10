#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // Creating the Adjacency List
    vector<int>adj[numCourses];
    for(auto it: prerequisites){
       int u = it[0];
        int v = it[1];
       adj[v].push_back(u);
   }
    // Creating the indegree list
    vector<int>indegree(numCourses,0);
    for(int i = 0; i < numCourses; i++){
        for(auto it: adj[i]){
           indegree[it]++;
       }
    }
    // Pushing the nodes with zero indegre into the queue
   queue<int>que;
    for(int i = 0; i < numCourses; i++){
        if(indegree[i] == 0)
           que.push(i);
   }
    // Finding the topological sort of the nodes
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
    if(ans.size() == numCourses)
        return ans;
    ans.clear();
    return ans;
}

int main(){

}