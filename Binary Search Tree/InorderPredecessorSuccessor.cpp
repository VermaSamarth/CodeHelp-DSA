// Assumption : All the non-leaf nodes must have left and right subtree.
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

int FindPredecessor(Node* root, int pre_num){
    if(root == nullptr || root->left == nullptr)
        return -1;
    
    if(root->data == pre_num){
        root = root->left;
        while(root->right != nullptr){
            root = root->right;
        }
        return root->data;
    }

    if(root->data > pre_num){
        return FindPredecessor(root->left, pre_num);
    }
    else 
        return FindPredecessor(root->right, pre_num);

}

int FindSuccessor(Node* root, int suc_num){
    if(root == nullptr || root->right == nullptr)
        return -1;

    if(root->data == suc_num){
        root = root->right;
        while(root->left != nullptr){
            root = root->left;
        }
        return root->data;
    }    
    
    if(root->data > suc_num){
        return FindSuccessor(root->left, suc_num);
    }
    else 
        return FindSuccessor(root->right, suc_num);
}

int main(){
    Node* root = nullptr;
    int pre_num, suc_num;
    cout << "Enter the Node data to create the tree: " << endl;  
    CreateBST(root);
    cout << "Enter the number whose predecessor is to be found: " << endl;
    cin >> pre_num;
    cout << "Enter the number whose successor is to be found: " << endl;
    cin >> suc_num;
    cout << "Predecessor: " << FindPredecessor(root, pre_num) << endl;
    cout << "Successor: " << FindSuccessor(root, suc_num) << endl;
    return 0;
}