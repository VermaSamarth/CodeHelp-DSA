#include<iostream>
using namespace std;
int diameter = 0;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            this->left = left;
            this->right = right;
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

int BTHeight(Node*&root){
    if(root == nullptr)
        return 0;
    int lh = BTHeight(root->left);
    int rh = BTHeight(root->right);
    int curr_diameter = lh + rh;
    diameter = max(curr_diameter, diameter);
    return max(lh, rh) + 1;
}

int main(){
    Node* root;
    root = BuildTree();
    int ans = BTHeight(root);
    cout << "Diameter of Tree: " << diameter << endl;
}