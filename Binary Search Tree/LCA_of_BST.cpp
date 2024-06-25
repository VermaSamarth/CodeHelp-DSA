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

Node* LowestCommonAncestor(Node* root, int p, int q){
    if(root == nullptr)
        return nullptr;
    

    if(p < root->data && q < root->data){
        return LowestCommonAncestor(root->left, p, q);
    }
    else if(p > root->data && q > root->data){
        return LowestCommonAncestor(root->right, p, q);
    }
    else
    // if((p > root->data && q < root->data) || (p < root->data && q > root->data))
        return root;
}

int main(){
    Node* root = nullptr;
    cout << "Enter the data for Node: " << endl;
    TakeData(root);
    int p, q;
    cout << "Enter the two number: " << endl;
    cin >> p >> q;
    Node* ans = LowestCommonAncestor(root, p, q);
    cout << "Ans: " << ans->data << endl; 
    return 0;
}