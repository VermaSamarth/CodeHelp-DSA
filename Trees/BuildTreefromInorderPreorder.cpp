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

int findPosition(int inorder[], int size, int element){
    for(int i = 0; i < size; i++){
        if(inorder[i] == element)
            return i;
    }
    return -1;
}

Node* BuildTreefromInorderPreorder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd){
    if(preIndex >= size || inorderStart > inorderEnd)
        return nullptr;
    int element = preorder[preIndex++];
    Node* root = new Node(element);
    int position = findPosition(inorder, size, element);
    root->left = BuildTreefromInorderPreorder(inorder, preorder, size, preIndex, inorderStart, position - 1);
    root->right = BuildTreefromInorderPreorder(inorder, preorder, size, preIndex, position + 1, inorderEnd);
    return root;
} 

void PostorderTraversal(Node* root){
    if(root == nullptr)
        return;
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout << root->data << " ";
    return;
}

int main(){
    int inorder[] = {40, 20, 50, 10, 60, 30, 70};
    int preorder[] = {10, 20, 40, 50, 30, 60, 70};
    int size = 7;
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = size;
    Node* root = BuildTreefromInorderPreorder(inorder, preorder, size, preIndex, inorderStart, inorderEnd);
    PostorderTraversal(root);
}
