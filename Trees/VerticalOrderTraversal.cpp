#include<iostream>
#include<map>
#include<vector>
#include<queue>
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

map<int,vector<int>> VerticalTraversal(Node* root){
    map<int,vector<int>> mapping;
    queue<pair<Node*,int>> que;
    que.push(make_pair(root, 0));
    while(!que.empty()){
        pair<Node*,int> frontNode = que.front();
        que.pop();
        Node* temp = frontNode.first;
        int hd = frontNode.second;
        mapping[hd].push_back(temp->data);
        if(temp->left != nullptr)
            que.push(make_pair(temp->left,hd - 1));
        if(temp->right != nullptr)
            que.push(make_pair(temp->right,hd + 1));
    }
    return mapping;
}

int main(){
    map<int,vector<int>> ump;
    Node* root = BuildTree();
    PreorderTraversal(root);
    cout << endl << "Vertical Order Traversal: " << endl;
    map<int,vector<int>> mapping = VerticalTraversal(root);
    for(auto it: mapping){
        int hd = it.first;
        vector<int> ans = it.second;
        cout << hd << " -> [ ";
        for(auto itr: ans)
            cout << itr << " ";
        cout << "] " << endl;
    }
}