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

int findMaxDepth(Node* root){
    if(root == nullptr)
        return 0;
    int lefttreedepth = findMaxDepth(root->left);
    int righttreedepth = findMaxDepth(root->right);
    int maxtreedepth = max(lefttreedepth,righttreedepth) + 1;
    return maxtreedepth;
}

int findDiameter(Node* root){
    if(root == nullptr)
        return 0;
    int opt1 = findDiameter(root->left);
    int opt2 = findDiameter(root->right);
    int opt3 = findMaxDepth(root->left) + findMaxDepth(root->right);
    int curr_max = max(opt1,opt2);
    return max(curr_max,opt3);
}

int main(){
    Node* root;
    root = BuildTree();
    cout << findDiameter(root) << endl;
}