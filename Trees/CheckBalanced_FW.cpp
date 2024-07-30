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

int CheckHeightBalanced(Node*&root, bool&isBalanced){
    if(!root)   return 0;
    int lh = CheckHeightBalanced(root->left, isBalanced);
    int rh = CheckHeightBalanced(root->right, isBalanced);
    if(isBalanced && abs(lh-rh)>1)
        isBalanced = false;
    return max(lh,rh) + 1;
}

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

int main(){
    Node* root;
    root = BuildTree();
    bool isBalanced = true;
    int ans = CheckHeightBalanced(root, isBalanced);
    if(isBalanced) cout << "It is a Height Balanced Tree. " << endl;
    else cout << "It is not a Height Balanced Tree. " << endl;
}