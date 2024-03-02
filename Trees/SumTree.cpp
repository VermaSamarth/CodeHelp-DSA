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

Node* Buildtree(){
    int data;
    cin >> data;
    if(data == -1)
        return nullptr;
    Node* root = new Node(data);
    root->left = Buildtree();
    root->right = Buildtree();
    return root;
}

int convertSumTree(Node* root){
    if(root == nullptr)
        return 0;
    int left = convertSumTree(root->left);
    int right = convertSumTree(root->right);
    root->data = left + right + root->data;
    return root->data;
}

int main(){
    Node* root;
    root = Buildtree();
    cout << "sum tree: " << convertSumTree(root) << endl;
}