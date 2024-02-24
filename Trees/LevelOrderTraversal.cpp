#include<iostream>
#include<queue>
using namespace std;

/*
    Steps to print the Level Order Traveral using queue.
        1. Push the root node into the queue.
        2. temp = que.front();
        3. que.pop();
        4. print popped data.
        5. Push the child node into the queue.
*/

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
    cout << "Enter the node data...." << endl;
    cin >> data;
    if(data == -1)
        return nullptr;
    Node* root = new Node(data);
    cout << "Left Tree of node:" << root->data << endl;
    root->left = BuildTree();
    cout << "Right Tree of node: " << root->data << endl;
    root->right = BuildTree();
    return root;
}

void LevelOrderTraverse(Node* root){
    queue<Node*> que;
    que.push(root);
    while(!que.empty()){
        Node* temp = que.front();
        que.pop();
        cout << temp->data << " ";
        if(temp->left != nullptr)
            que.push(temp->left);
        if(temp->right != nullptr)
            que.push(temp->right);
    }
}

int main(){
    Node* root;
    root = BuildTree();
    LevelOrderTraverse(root);
}