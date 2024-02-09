#include<iostream>
#include<vector>
using namespace std;

bool checkCharacter(string str, char x){
    for(int i = 0; i < str.length(); i++){
        if(str[i] == x)
            return true;
    }
    return false;
}

vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int> index;
    for(int i = 0; i < words.size(); i++){
        if(checkCharacter(words[i],x)){
            index.push_back(i);
        }
    }
    return index;
}

int main(){
    vector<string> arr = {"Samarth", "Verma"};
    char chr = 'a';
    vector<int> ans = findWordsContaining(arr,chr);
    cout << "Strings including the character are: " << endl;
    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
}
