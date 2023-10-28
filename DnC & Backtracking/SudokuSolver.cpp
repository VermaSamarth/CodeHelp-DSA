#include<iostream>
#include<vector>
using namespace std; 

bool isSafe(int value, int board[9][9], int i, int j){
    // Row Check
    for(int col = 0; col < 9; col++){
        if(board[i][col] == value)
            return false;
    }

    // Column Check
    for(int row = 0; row < 9; row++){
        if(board[row][j] == value)
            return false;
    }

    // 3X3 Matrix Box Check
    for(int m = 0; m < 9; m++){
        if(board[3*(i/3)+(m/3)][3*(j/3)+(m%3)] == value)
            return false;
    }

    return true;
}

// Below function returns true or false depending on the answer we found.
bool solve(int board[9][9], int n){
    // No Base Condition in this solution

    // Loop to traverse through the 2D array/ Sudoku Board
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            // Check for empty cell i.e., value in cell -> 0
            if(board[i][j] == 0){
                for(int value = 1; value < 10; value++){
                //Checking if the number is safe to put or not.
                    if(isSafe(value,board,i,j)){
                        board[i][j] = value;
                        // Recursive Call
                        bool ans = solve(board,n);
                        if(ans == true)
                            return ans;
                        // Backtracking
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    // 0 -> Represents Empty cell
    int board[9][9] = { {4,5,0,0,0,0,0,0,0},
                        {0,0,2,0,7,0,6,3,0},
                        {0,0,0,0,0,0,0,2,8},
                        {0,0,0,9,5,0,0,0,0},
                        {0,8,6,0,0,0,2,0,0},
                        {0,2,0,6,0,0,7,5,0},
                        {0,0,0,0,0,0,4,7,6},
                        {0,7,0,0,4,5,0,0,0},
                        {0,0,8,0,0,9,0,0,0} };
    int n = 9;
    solve(board,n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] <<" ";
        }
        cout << endl;
    }
}