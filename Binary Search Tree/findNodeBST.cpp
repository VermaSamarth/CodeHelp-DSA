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

bool SearchNodeBST(Node* root, int data){
    if(root == nullptr)
        return false;
    
    if(root->data == data)
        return true;

    if(data > root->data){
        return SearchNodeBST(root->right, data);
    }
    else{
        return SearchNodeBST(root->left, data);
    }
}

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

int main(){
    Node* root = nullptr;
    int num;
    cout << "Enter the Node data to create the tree: " << endl;  
    CreateBST(root);
    cout << "\nPrinting the BST in Inorder Traversal: " << endl;
    InorderTraversal(root);
    cout << endl;
    cout << "Enter the element to be found: " << endl;  
    cin >> num;
    if(SearchNodeBST(root, num) == 1)
        cout << "Element found!!!!" << endl;
    else    
        cout << "Element not found!!!!" << endl;
}