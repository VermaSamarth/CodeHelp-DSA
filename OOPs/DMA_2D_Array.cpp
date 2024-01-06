#include<iostream>
using namespace std;

int main(){
    int row = 5;    // Created in the stack
    int col = 6;    // Created in the stack  

    int** arr = new int*[row];      // Created in the Heap Memory
    
    for(int i = 0; i < row; i++){
        arr[i] = new int[col];      // Created in the Heap Memory
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < row; i++){
        delete []arr[i];
    }
    delete []arr;
}