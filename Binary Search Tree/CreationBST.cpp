#include<iostream>
#include <queue>
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

void LevelOrderTraversal_Linewise(Node* root){
    queue<Node*> level;
    // Step 1
    level.push(root);
    level.push(NULL);
    while(!level.empty()){
        // Step 2
        Node* temp = level.front();
        // Step 3
        level.pop();
        // Step 4
        if(temp == NULL){
            cout << endl;           // Changing the line.
            if(!level.empty()){
                level.push(NULL);
            }
        }
        else{
            // Step 5
            cout << temp->data << " ";
            // Step 6
            if(temp->left != nullptr)
                level.push(temp->left);
            if(temp->right != nullptr)
                level.push(temp->right);
        }
    }
}

void PreorderTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    cout << root->data << " ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
    return;
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

void PostorderTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout << root->data << " ";
    return;
}

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

int main(){
    Node* root = nullptr;
    cout << "Enter the data for Node: " << endl;
    TakeData(root);
    cout << "\nPrinting the tree: " << endl;
    LevelOrderTraversal_Linewise(root);
    cout << "\nPreorder Traversal: " << endl;
    PreorderTraversal(root);
    cout << endl;
    cout << "\nInorder Traversal: " << endl;
    InorderTraversal(root);
    cout << endl;
    cout << "\nPostorder Traversal: " << endl;
    PostorderTraversal(root);
    cout << endl;
    return 0;
}