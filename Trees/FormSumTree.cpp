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

Node* buildtree(){
    int data;
    cin >> data;
    if(data == -1)
        return nullptr;
    Node* root = new Node(data);
    root->left = buildtree();
    root->right = buildtree();
    return root;
}

int FormSumTree(Node*&root){
    if(root == nullptr)
        return 0;
    int leftSum = FormSumTree(root->left);
    int rightSum = FormSumTree(root->right);
    root->data = root->data + leftSum + rightSum;
    return root->data;
}

void InorderTraversal(Node* root){
    if(root == nullptr)
        return ;
    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
    return;
}

int main(){
    Node* root = nullptr;
    root = buildtree();
    cout << "Before Sum tree formed : " << endl;
    InorderTraversal(root);
    cout << endl << "After Sum tree formed : " << endl;
    int ans = FormSumTree(root);
    InorderTraversal(root);
    cout << endl << "Root Sum = " << ans << endl;
}