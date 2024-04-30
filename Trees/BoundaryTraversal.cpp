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

void LeftBoundary(Node* root){
    if((root == nullptr) || (root->left == nullptr && root->right == nullptr))
        return;
    cout << root->data << " ";
    if(root->left)
        LeftBoundary(root->left);
    else
        LeftBoundary(root->right);
    return;
}

void LeafBoundary(Node* root){
    if(root == nullptr)
        return;
    if(root->left == nullptr && root->right == nullptr){
        cout << root->data << " ";
        return;
    }
    LeafBoundary(root->left);
    LeafBoundary(root->right);
    return;
}

void RightBoundary(Node* root){
    if((root == nullptr) || (root->left == nullptr && root->right == nullptr))
        return;
    if(root->right)
        RightBoundary(root->right);
    else
        RightBoundary(root->left);
    cout << root->data << " ";
    return;
}

void boundaryTraversal(Node* root){
    if(root == nullptr)
        return;
    cout << root->data << " ";
    if(root->left == nullptr && root->right == nullptr)
        return;
    // Step 1: Left Side Printing
    LeftBoundary(root->left);
    // Step 2: Leaf Node Printing
    LeafBoundary(root);
    // Step 3: Right Side Printing 
    RightBoundary(root->right);
}

int main(){
    Node* root = BuildTree();
    cout << "Boundary Traversal: " << endl;
    boundaryTraversal(root);
}