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

int maxHeight(Node* root){
    if(root == nullptr)
        return 0;
    int leftHeight = maxHeight(root->left);
    int rightHeight = maxHeight(root->right);
    int maxheight = max(leftHeight,rightHeight) + 1;
    return maxheight;
}

int main(){
    Node* root;
    root = Buildtree();
    cout << "Maximum Height of the tree: " << maxHeight(root) << endl;
    // PostorderTraversal(root);
    // InorderTraversal(root);
}