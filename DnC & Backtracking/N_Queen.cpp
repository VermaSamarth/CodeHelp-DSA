#include<iostream>
#include<vector>
using namespace std;
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
    // Here the time complexity is O(n); 
    int i = row;
    int j = col;
    // Checking left rows
    while(j >= 0){
        if(board[i][j] == 'Q')
            return false;
        j--;
    }
    // Checking Top Left Diagonal
    i = row;
    j = col;
    while(i >= 0 && j >= 0){
        if(board[i][j] == 'Q')
            return false;
        i--;
        j--;
    }
    // Checking Bottom Left Diagonal
    i = row;
    j = col;
    while(i < n && j >= 0){
        if(board[i][j] == 'Q')
            return false;
        i++;
        j--;
    }
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
            board[row][col] = 'Q';
            // Recursive Call
            solve(board,col+1,n);
            // BackTracking
            board[row][col] = '-';
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