#include<iostream>
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

bool checkTree(Node* root){
    if(root->data == (root->left->data + root->right->data))
        return true;
    return false;
}

int main(){
    Node* root;
    root = Buildtree();
    cout << "Answer: " << checkTree(root) << endl;
}