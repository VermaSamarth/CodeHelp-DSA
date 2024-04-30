#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	// Write your code here.
	int row[4] = {0};
	int col[5] = {0};
    // for(int i = 0; i < n; i++)
    //     cout << row[i] << " ";
    // cout << endl;
    // for(int i = 0; i < m; i++)
    //     cout << col[i] << " ";
    // cout << endl << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == 0){
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
    // for(int i = 0; i < n; i++)
    //     cout << row[i] << " ";
    // cout << endl;
    // for(int i = 0; i < m; i++)
    //     cout << col[i] << " ";
    // cout << endl << endl;
	vector<vector<int>> ans(n, vector<int>(m,0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(row[i] == 0 && col[j] == 0){
				ans[i][j] = matrix[i][j];
			}
		}
	}
	return ans;
}

int main(){
    vector<vector<int>> matrix = {{6,5,1,6,8},{2,8,0,7,5},{4,4,0,6,2},{9,6,3,7,5}};
    int n = 4, m = 5;
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);
    for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << ans[i][j] << " ";
		}
        cout << endl;
	}
}