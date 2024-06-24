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

int findMinimum(Node* root){
    if(root == nullptr){
        return -1;
    }

    while(root->left != nullptr){
        root = root->left;
    }

    return root->data;
}

int findMaximum(Node* root){
    if(root == nullptr){
        return -1;
    }

    while(root->right != nullptr){
        root = root->right;
    }

    return root->data;
}

int main(){
    Node* root = nullptr;
    int num;
    cout << "Enter the Node data to create the tree: " << endl;  
    CreateBST(root);
    cout << "\nMinimum Element: " << findMinimum(root) << endl;
    cout << "\nMaximum Element: " << findMaximum(root) << endl;
    return 0;
}