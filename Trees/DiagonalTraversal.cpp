#include<iostream>
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

vector<int> DiagonalTraversal(Node*&root){
    vector<int> ans;
    queue<Node*> que;
    que.push(root);
    while (!que.empty()){
        Node* temp = que.front();
        que.pop();
        while(temp){
            ans.push_back(temp->data);
            if(temp->left != nullptr)
                que.push(temp->left);
            temp = temp->right;
        }
    }
    return ans;
}

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

int main(){
    Node* root;
    root = BuildTree();
    vector<int> ans = DiagonalTraversal(root);
    cout << "Diagonal Traversal: ";
    for(auto it: ans)
        cout << it << " ";
    cout << endl;
}