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

    Node* root = new Node(data);
    cout << "Entering the left part of the tree!!!" << endl;
    root->left = buildtree();
    cout << "Entering the right part of the tree!!!" << endl;
    root->right = buildtree();

    return root;
}

int main(){
    Node* root = nullptr;
    root = buildtree();

    cout << "Root node: " << root << endl;
}