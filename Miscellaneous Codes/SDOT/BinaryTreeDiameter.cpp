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

int heightofTree(Node* root){
    if(root == nullptr)
        return 0;
    int leftheight = heightofTree(root->left);
    int rightheight = heightofTree(root->right);
    return max(leftheight,rightheight) + 1;
}

int diameterofTree(Node* root){
    if(root == nullptr)
        return  0;
    int leftdia = diameterofTree(root->left);
    int rightdia = diameterofTree(root->right);
    int leftright = heightofTree(root->left) + heightofTree(root->right) + 1;

    return max(leftright,max(leftdia,rightdia));
}

Node* BuildtBst(Node* root, int data){
    if(root == nullptr){
        Node* newNode = new Node(data);
        root = newNode;
        return root;    
    }
    if(data < root->data)
        root->left = BuildtBst(root->left,data);
    else
        root->right = BuildtBst(root->right,data);
    return root;
}

int main(){
    int data;
    cin >> data;
    Node* root = nullptr;
    while(data != -1){
        root = BuildtBst(root,data);
        cin >> data;
    }
    cout << "Diameter: " << diameterofTree(root) << endl;
}