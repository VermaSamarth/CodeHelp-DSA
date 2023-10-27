#include<iostream>
#include<vector>
using namespace std;

void solve(int& num, int open, int close, string output, vector<string>& ans){
    // Base Condition
    if(open == 0 && close == 0){
        ans.push_back(output);
        return;
    }

    // Inserting open parenthesis
    if(open > 0){
        output.push_back('(');
        solve(num,open-1,close,output,ans);
        // Backtracking
        output.pop_back();
    }

    // Inserting open parenthesis
    if(open < close){
        output.push_back(')');
        solve(num,open,close-1,output,ans);
        // Backtracking
        output.pop_back();
    }

}

int main(){
    int num;
    cout << "Enter the number: " << endl;
    cin >> num;
    vector<string> ans;
    string output = "";
    int open = num;
    int close = num;
    solve(num,open,close,output,ans);
    for(auto val : ans)
        cout << val << " ";
    cout << endl;
}