#include <iostream>
#include <vector>
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

void InorderTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
    return;
}

Node* Create_BST_from_array(vector<int> arr, int start, int end){
    // Base Case
    if(start > end){
        return nullptr;
    }

    // Finding the middle
    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);
    root->left = Create_BST_from_array(arr, start, mid - 1);
    root->right = Create_BST_from_array(arr,mid + 1, end);
    return root;
}

int main(){
    // Node* root = nullptr;
    // cout << "Enter the data for Node: " << endl;
    // TakeData(root);
    vector<int> arr = {10,20,30,40,50,60,70,80,90,100,110};
    Node* root = Create_BST_from_array(arr, 0, arr.size() - 1);
    cout << "Inorder Traversal of the BST: " << endl;
    InorderTraversal(root);
}