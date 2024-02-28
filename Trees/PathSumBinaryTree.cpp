#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

Node* BuildTree(){
    int data;
    cin >> data;
    if(data == -1)
        return nullptr;
    Node* root = new Node(data);
    root->left = BuildTree();
    root->right = BuildTree();
    return root;
}

void FindPathSum(Node* root, vector<int>& allsums, int ans){
    if(root == nullptr){
        return;
    }
    ans = ans + root->data;
    FindPathSum(root->left,allsums,ans);
    FindPathSum(root->right,allsums,ans);
    if(root->left == nullptr && root->right == nullptr)
        allsums.push_back(ans);
    return;
}

int main(){
    Node* root;
    root = BuildTree();
    int sum = 22;
    vector<int> allsums;
    int ans = 0;
    FindPathSum(root,allsums,ans);
    ans = 0;
    for(auto it:allsums){
        if(it == sum){
            cout << "Path found successfully." << endl;
            ans = 1;
        }
    }
    if(ans == 0)
        cout << "Path not found." << endl;
}