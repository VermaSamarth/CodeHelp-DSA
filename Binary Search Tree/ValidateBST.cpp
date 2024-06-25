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

bool ValidatingBST(Node* root, int lower, int upper){
    if(root == nullptr)
        return true;

    if(root->data < upper && root->data > lower){
        bool left_ans = ValidatingBST(root->left, lower, root->data);
        bool right_ans = ValidatingBST(root->right, root->data, upper);
        return left_ans && right_ans;
    }
    else{
        return false;
    }
}

int main(){
    Node* root = nullptr;
    cout << "Enter the data for Node: " << endl;
    TakeData(root);
    bool ans = ValidatingBST(root, INT_MIN, INT_MAX);
    cout << "Ans: " << ans << endl;
}