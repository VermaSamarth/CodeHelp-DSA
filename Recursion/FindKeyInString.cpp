#include<iostream>
#include<vector>
using namespace std;

void findKey(string str, int len, int index, char chr){
    //Base Condition
    if(index>=len){
        return;
    }
    if(str[index] == chr)
        cout << "Found at: " << index << endl;
    return findKey(str,len,index+1,chr);
}

void returnIndex(string& str, int& len, int i, char& chr, vector<int>& ans){
    //Base Condition
    if(i>=len)
        return;

    if(str[i] == chr)
        ans.push_back(i);

    return returnIndex(str,len,i+1,chr,ans);
}


int main(){
    string str = "lovebabbar";
    char chr = 'b';
    int len = str.length();
    int index = 0;
    vector<int> ans;
    findKey(str,len,index,chr);
    returnIndex(str,len,index,chr,ans);
    for(auto val:ans){
        cout << val << " ";
    }
    cout << endl;
}