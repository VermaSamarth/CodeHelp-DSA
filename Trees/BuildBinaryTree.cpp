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
    cout << "Enter the node data: " << endl;
    cin >> data;

    if(data == -1){
        return nullptr;
    }

    // Step 1: Create the root
    Node* root = new Node(data);
    cout << "Entering the left part of the tree for node: "<< root->data << endl;
    // Step 2: Create the left node
    root->left = buildtree();
    cout << "Entering the right part of the treefor node: "<< root->data << endl;
    // Step 2: Create the right node
    root->right = buildtree();

    return root;
}

// Simplified code
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
    Node* root = nullptr;
    // root = buildtree();
    root = BuildTree();

    cout << "Root node: " << root->data << endl;
}