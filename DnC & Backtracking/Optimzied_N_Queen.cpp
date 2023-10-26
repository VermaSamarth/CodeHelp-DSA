#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Creating the maps
unordered_map<int,bool> rowCheck;
unordered_map<int,bool> topLeftDiag;
unordered_map<int,bool> bottomLeftDiag;

// Printing the Solution
void printSolution(vector<vector<char>> board, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}

// Checking if the particular position is safe to join or not
bool isSafe(int row, int col, vector<vector<char>> board, int n){
    // Here the time complexity is O(1)
    if(rowCheck[row] == true)
        return false;
    if(topLeftDiag[n+col-row] == true)
        return false;
    if(bottomLeftDiag[row+col] == true)
        return false;
    return true;
}

void solve(vector<vector<char>> board, int col, int n){
    // Base Case
    if(col >= n){
        printSolution(board,n);
        return;
    }

    // Processing
    for(int row = 0; row < n; row++){
        // Whether placing the queen there is SAFE or NOT.
        if(isSafe(row,col,board,n)){
            // Updating the values in the map
            board[row][col] = 'Q';
            rowCheck[row] = true;
            topLeftDiag[n-row+col] = true;
            bottomLeftDiag[row+col] = true;
            
            // Recursive Call
            solve(board,col+1,n);
            
            // BackTracking & reverting the values in the map
            board[row][col] = '-';
            rowCheck[row] = false;
            topLeftDiag[n-row+col] = false;
            bottomLeftDiag[row+col] = false;
        }
    }
}

int main(){
    int n = 4;
    // Cell = 0 --> Empty Cell --> Queen not there
    // Cell = 1 --> Occupied Cell --> Queen is there
    vector<vector<char>> board(n,vector<char>(n,'-'));
    int col = 0;
    solve(board,col,n);
}