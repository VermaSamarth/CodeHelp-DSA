#include<iostream>
#include<vector>
using namespace std;

void findSequence(vector<string>& subseq,string& s, string output, int& n, int i){
    // Base Case
    // When the entire string is traversed.
    if(i == n){
        // Printing the created subsequence.
        // cout << output << endl;

        // Storing the value in the vector instead of directly printing.
        subseq.push_back(output);
        return;
    }
    // Include Character
    findSequence(subseq, s, output + s[i] + "", n , i+1);
    // Exclude Character
    findSequence(subseq, s, output, n, i+1);
}

int main(){
    string str = "abc";
    string output  = "";
    vector<string> subseq;
    int len = str.length();
    int i = 0;
    cout << "Subsequences of the string : " << endl;
    findSequence(subseq,str,output,len,i);
    for(auto val:subseq)
        cout<< val << endl;
}