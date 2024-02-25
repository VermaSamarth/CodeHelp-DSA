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

void PostorderTraversal(Node* root){
    if(root == nullptr)
        return;
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout << root->data << " ";
    return;
}

int main(){
    Node* root;
    root = Buildtree();
    cout << "Postorder Traversal: " << endl;
    PostorderTraversal(root);
    // InorderTraversal(root);
}