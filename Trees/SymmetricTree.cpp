#include<iostream>
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

bool IsSymmetricTree(Node*&root1, Node*&root2){
    if(root1 == nullptr && root2 == nullptr)
        return true;
    if(root1 != nullptr && root2 != nullptr)
        return (root1->data == root2->data)
               && IsSymmetricTree(root1->left, root2->right) 
               && IsSymmetricTree(root1->right, root2->left);
    return false;
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
    bool ans = IsSymmetricTree(root->left, root->right);
    if(ans) cout << "Symmetric Tree." << endl;
    else    cout << "Not Symmetric Tree." << endl;
}