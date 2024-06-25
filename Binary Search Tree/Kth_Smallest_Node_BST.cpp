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

int kth_Smallest(Node* root, int &k){
    if(root == nullptr)
        return -1;
    
    int left_ans = kth_Smallest(root->left, k);
    if(left_ans != -1)  
        return left_ans;
    k--;
    if(k == 0)  
        return root->data;
    int right_ans = kth_Smallest(root->right, k);
    return  right_ans;
}

int main(){
    Node* root = nullptr;
    cout << "Enter the data for Node: " << endl;
    TakeData(root);
    int k;
    cout << "Inorder Traversal: " << endl;
    InorderTraversal(root);
    cout << endl << "Enter the number: " << endl;
    cin >> k;
    cout << "Ans: " << kth_Smallest(root, k);
}