#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void solve(int index, string& str, string output, vector<string>& ans, unordered_map<int,string>& mapping){
    // Base Case
    if(index >= str.length()){
        ans.push_back(output);
        return;
    }
    // Finding out the number in the string.
    int pos = str[index] - '0';     // Converting string number to integer number 
    string value = mapping[pos];
    // Loop to traverse through each number's string
    for(int i = 0; i < value.length(); i++){
        output.push_back(value[i]);
        solve(index+1,str,output,ans,mapping);
        // Backtracking
        output.pop_back();
    }
}

int main(){
    unordered_map<int,string> mapping;
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";
    string str;
    cout << "Enter the keypad numbers: " << endl;
    cin >> str;

    vector<string> ans;
    string output = "";
    int index = 0;
    solve(index,str,output,ans,mapping);
    for(auto val : ans)
        cout << val << " ";
    cout << endl;
}