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

void PreorderTraversal(Node* root){
    if(root == nullptr)
        return ;
    cout << root->data << " ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
    return;
}

void leftView(Node* root, int level, vector<int>&ans){
    if(root == nullptr)
        return;
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    leftView(root->left, level + 1, ans);
    leftView(root->right, level + 1, ans);
    return;
}

int main(){
    Node* root = BuildTree();
    vector<int> ans;
    cout << "Printing the Tree: ";
    PreorderTraversal(root);
    cout << endl << endl << "Left View of the tree: ";
    leftView(root, 0, ans);
    for(auto it: ans)
        cout << it << " ";
    cout << endl;
}