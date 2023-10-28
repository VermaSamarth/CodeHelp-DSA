/*
 Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

 Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
 Each vowel 'a' may only be followed by an 'e'.
 Each vowel 'e' may only be followed by an 'a' or an 'i'.
 Each vowel 'i' may not be followed by another 'i'.
 Each vowel 'o' may only be followed by an 'i' or a 'u'.
 Each vowel 'u' may only be followed by an 'a'.
 Since the answer may be too large, return it modulo 10^9 + 7.
*/

// Leetcode Question: Answer is correct but throwing TLE. Can be done better with Dynamic Programming
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<math.h>
using namespace std;

void solve(int& n, int& ans, int index, string& output, unordered_map<char,string>& mapping){
        // Base Condition
        if(index >= n){
            ans = ans +  1;
            ans = ans % (int)(pow(10,9) + 7);
            cout << output << " ";
            return;
        }
        int position = output.length() - 1;
        char chr = output[position];
        string value = mapping[chr];
        for(int i = 0; i < value.length(); i++){
            output.push_back(value[i]);
            solve(n,ans,index+1,output,mapping);
            output.pop_back();
        }
    }
    int main() {
        int n;
        cout << "Enter the value of N: " << endl;
        cin >> n;
        int ans = 0;
        int index = 0;
        string output = " ";
        // Using maps to store cases for creating combinations
        unordered_map<char,string> mapping;
        mapping[' '] = "aeiou";
        mapping['a'] = "e";
        mapping['e'] = "ai";
        mapping['i'] = "aeou";
        mapping['o'] = "iu";
        mapping['u'] = "a";
        solve(n,ans,index,output,mapping);
        cout << endl;
        cout << "Answer: " << ans << endl;
        // return ans;
    }