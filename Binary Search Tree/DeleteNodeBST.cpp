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

Node* InsertIntoBST(Node*&root, int data){
    if(root == nullptr){
       root = new Node(data);
       return root;
    }

    if(root->data < data)
        root->right = InsertIntoBST(root->right, data);
    else    
        root->left = InsertIntoBST(root->left, data);
    
    return root;

}

void TakeData(Node* &root){
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

int findPredecessor(Node* root){
    if(root == nullptr || root->left == nullptr)
        return -1;
    while(root->right != nullptr){
        root = root->right;
    }
    return root->data;
}

Node* DeleteFromBST(Node* root, int target){
    // Base case
    if(root == nullptr)
        return nullptr;

    if(root->data == target){
        // Agar dono left and right child are null
        if(root->left == nullptr && root->right == nullptr){
            // delete root;
            return nullptr;
        }
        // Agar right child is null and left child is not null
        else if(root->right == nullptr && root->left != nullptr){
            Node* child = root->left;
            // delete root;
            return child;
        }
        // Agar right child is not null and left child is null
        else if(root->right != nullptr && root->left == nullptr){
            Node* child = root->right;
            // delete root;
            return child;
        }
        // Agar both right child and left child are not null
        else{
            int inorderPred = findPredecessor(root->left);
            root->data = inorderPred;
            root->left = DeleteFromBST(root->left,inorderPred);
            return root;
        }
    }

    if(root->data < target)
        root->right = DeleteFromBST(root->right, target);
    else
        root->left =  DeleteFromBST(root->left, target);
    
    return root;
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
    cout << "Enter the data for Node: " << endl;
    TakeData(root);     
    int target;
    cout << "Enter the target to be deleted: " << endl;
    cin >> target;
    cout << "Inorder of Tree before deletion: " << endl;
    InorderTraversal(root);
    root = DeleteFromBST(root,target);
    cout << endl << "Inorder of Tree after traversal: " << endl;
    InorderTraversal(root);
    return 0;
}