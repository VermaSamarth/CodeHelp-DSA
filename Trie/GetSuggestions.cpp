#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char data){
            this->data = data;
            for(int i = 0; i < 26; i++)
                children[i] = nullptr;
            this->isTerminal = false;
        }
};

void InsertWord(TrieNode* root, string word){
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    char chr = word[0];
    int index = chr - 'a';
    TrieNode* child;
    if(root->children[index] != nullptr){
        child = root->children[index];
    }
    else{
        child = new TrieNode(chr);
        root->children[index] = child;
    }
    InsertWord(child, word.substr(1));
}

void storeSuggestions(TrieNode* current, vector<string> &temp, string &prefix){
    if(current->isTerminal){
        // cout << prefix << endl;
        temp.push_back(prefix);
    }
    for(char ch = 'a'; ch <= 'z'; ch++){
        int index = ch - 'a';
        TrieNode* next = current->children[index];
        if(next != nullptr){
            prefix.push_back(ch);
            storeSuggestions(next, temp, prefix);
            prefix.pop_back();
        }
    }
}

vector<vector<string>> GetSuggestion(TrieNode* root, string &search){
    TrieNode* prev = root;
    vector<vector<string>> ans;
    string prefix = "";

    for(int i = 0; i < search.length(); i++){
        char last_chr = search[i];
        prefix.push_back(last_chr);
        int index = last_chr - 'a';
        TrieNode* current = prev->children[index];
        if(current == nullptr)
            break;
        else{
            vector<string> temp;
            storeSuggestions(current, temp, prefix);
            ans.push_back(temp);
            prev = current;
        }
    }
    return ans;
}

int main(){
    vector<string> v;
    v.push_back("love");
    v.push_back("lover");
    v.push_back("loving");
    v.push_back("lane");
    v.push_back("last");
    v.push_back("lost");
    v.push_back("lord");

    string search = "lovi";

    TrieNode* root = new TrieNode('-');
    for(int i = 0; i < v.size(); i++){
        InsertWord(root, v[i]);
    }

    vector<vector<string>> ans = GetSuggestion(root, search);

    cout << "Printing the suggestions: " << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << search[i] << " -> ";
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}