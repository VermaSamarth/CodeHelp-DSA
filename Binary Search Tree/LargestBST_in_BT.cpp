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

class NodeValue{
    public:
        int maxNode;
        int minNode;
        int size;

        NodeValue(int maxNode, int minNode, int size){
            this->maxNode = maxNode;
            this->minNode = minNode;
            this->size = size;
        }
};

Node* InsertIntoBST(Node* root, int data){
    if(root == nullptr){
        root = new Node(data);
        return root;
    }

    if(root->data < data){
        root->right = InsertIntoBST(root->right, data);
    }
    else{
        root->left = InsertIntoBST(root->left, data);
    }
    return root;
}

void CreateBST(Node* &root){
    int data;
    cin >> data;
    while(data != -1){
        root = InsertIntoBST(root, data);
        cin >> data;
    }
}

void InorderTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
    return;
}

NodeValue LargestBST_Helper(Node* root){
    if(root == nullptr){
        return NodeValue(INT_MIN, INT_MAX, 0);
    }

    auto left = LargestBST_Helper(root->left);
    auto right = LargestBST_Helper(root->right);

    if(left.maxNode < root->data && right.minNode > root->data){
        return NodeValue(max(root->data, right.maxNode), min(root->data, left.minNode), (left.size + right.size + 1));
    }

    return NodeValue(INT_MAX, INT_MIN, max(left.size, right.size));
}

int largestBST(Node* root){
    return LargestBST_Helper(root).size;
}

int main(){
    Node* root = nullptr;
    int num;
    cout << "Enter the Node data to create the tree: " << endl;  
    CreateBST(root);
    cout << "\nPrinting the BST in Inorder Traversal: " << endl;
    InorderTraversal(root);
    cout << endl;
    cout << "Answer: " << largestBST(root) << endl;
}