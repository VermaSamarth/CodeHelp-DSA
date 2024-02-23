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

Node* BuildNodeInTree(){
    int data;
    cout << "Enter the value of the node: " << endl;
    cin >> data;

    if(data == -1){
        return nullptr;
    }
    Node* root = new Node(data);
    cout << root->data << " -> left :";
    cout << endl;
    root->left = BuildNodeInTree();
    cout << root->data << " -> right :";
    cout << endl;
    root->right = BuildNodeInTree();

    return root;
}


int main(){
    Node* root = nullptr;
    root = BuildNodeInTree();

    cout << root->data << endl;
}