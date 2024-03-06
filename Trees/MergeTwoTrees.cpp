#include<iostream>
#include<queue>
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

Node* MergeBinaryTree(Node* root1, Node* root2){
    if(root1 == nullptr)
        return root2;
    if(root2 == nullptr)
        return root1;
        
}

int main(){
    Node* root;
    root = Buildtree();

}