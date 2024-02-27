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

Node* BuildTree(){
    int data;
    cin >> data;
    if(data == -1)
        return nullptr;
    Node* root = new Node(data);
    root->left = BuildTree();
    root->right = BuildTree();
    return root;
}

bool SameTree(Node* root1, Node* root2){
    if(root1 == nullptr && root2 == nullptr)
        return true;
    if(root1 == nullptr || root2 == nullptr)
        return false;
    bool curr = (root1->data == root2->data);
    bool curr_left = SameTree(root1->left,root2->left);
    bool curr_right = SameTree(root1->right,root2->right);
    return (curr && curr_left && curr_right);
}

int main(){
    Node* root1;
    Node* root2;
    root1 = BuildTree();
    root2 = BuildTree();
    cout << SameTree(root1,root2) << endl;
}