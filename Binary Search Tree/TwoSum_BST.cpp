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

void InorderTraversal(Node* root, vector<int> &inorder){
    if(root == nullptr){
        return;
    }
    InorderTraversal(root->left, inorder);
    // cout << root->data << " ";
    inorder.push_back(root->data);
    InorderTraversal(root->right, inorder);
    return;
}

bool CheckSumExists(vector<int> inorder, int num){
    int start = 0;
    int end = inorder.size() - 1;
    while(start < end){
        if(inorder[start] + inorder[end] > num)
            end--;
        else if(inorder[start] + inorder[end] < num)
            start++;
        else    
            return true;
    }
    return false;
}

int main(){
    Node* root = nullptr;
    cout << "Enter the data for Node: " << endl;
    TakeData(root);
    int num;
    cout << "Sum Number: " << endl;
    cin >> num;
    vector<int> inorder;
    InorderTraversal(root, inorder);
    cout << "Inorder Traversal of the BST: " << endl;
    for(auto it: inorder)
        cout << it << " ";
    cout << endl << "Sum possible? " << CheckSumExists(inorder, num) << endl;
}