#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int srcx, int srcy, int row, int col, int arr[3][3], vector<vector<bool>>& visited){
    // Three conditions to check:
    // 1. row_index < rows & col_index < columns
    // 2. Index is already visited or not.
    // 3. Current Index is 1 or not.
    if(((srcx < row && srcx >= 0) && (srcy >= 0 && srcy < col)) &&(visited[srcx][srcy] != true) && (arr[srcx][srcy] == 1))
        return true;
    else
        return false;
}   

void solveMaze(int arr[3][3], int row, int col, int srcx, int srcy, vector<vector<bool>>& visited, vector<string>& path, string output){
    // Base Case
    if(srcx == row - 1 && srcy == col - 1){
        path.push_back(output);
        return;
    }
    // Down -> i+1, j
    if(isSafe(srcx + 1, srcy, row, col, arr, visited)){
        visited[srcx+1][srcy] = true;
        // Movement
        solveMaze(arr,row,col,srcx+1,srcy,visited,path,output + 'D');
        // BackTracking
        visited[srcx+1][srcy] = false;
    } 

    // Left -> i, j-1
    if(isSafe(srcx, srcy - 1, row, col, arr, visited)){
        visited[srcx][srcy-1 ] = true;
        // Movement
        solveMaze(arr,row,col,srcx,srcy-1,visited,path,output + 'L');
        // BackTracking
        visited[srcx][srcy-1] = false;
    } 

    // Right -> i, j+1
    if(isSafe(srcx, srcy + 1, row, col, arr, visited)){
        visited[srcx][srcy+1] = true;
        // Movement
        solveMaze(arr,row,col,srcx,srcy+1,visited,path,output + 'R');
        // BackTracking
        visited[srcx][srcy+1] = false;
    } 

    // Up -> i-1, j
    if(isSafe(srcx - 1, srcy, row, col, arr, visited)){
        visited[srcx-1][srcy] = true;
        // Movement
        solveMaze(arr,row,col,srcx-1,srcy,visited,path,output + 'U');
        // BackTracking
        visited[srcx-1][srcy] = false;
    } 
}

int main(){
    // Maze
    int maze[3][3] = {{1,0,0}, {1,1,0}, {1,1,1}};
    int row = 3;
    int col = 3;
    
    // If source only 0
    if( maze[0][0] == 0){
        cout << "No Path Exists: Source is Zero...." << endl;
        return 0;
    }
    // Array to stored visited indices.
    vector<vector<bool>> visited(row,vector<bool>(col,false));
    visited[0][0] = true;
    vector<string> path;
    string output;

    solveMaze(maze,row,col,0,0,visited,path,output);

    cout << "Printing the Maze results: " << endl;
    for(auto val:path)
        cout << val << " ";
    cout << endl;

    if(path.size() == 0)
        cout << "No Valid Path found!!!!" << endl;
} 