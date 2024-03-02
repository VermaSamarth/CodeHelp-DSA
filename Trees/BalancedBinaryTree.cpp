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

Node* Buildtree(){
    int data;
    cin >> data;
    if(data == -1)
        return nullptr;
    Node* root = new Node(data);
    root->left = Buildtree();
    root->right = Buildtree();
    return root;
}

int findHeight(Node* root){
    if(root == nullptr)
        return 0;
    
    int leftside = findHeight(root->left);
    int rightside = findHeight(root->right);
    int curr_max = max(leftside,rightside) + 1;
    return curr_max;
}

bool isBalanced(Node* root){
    // Base Case
    if(root == nullptr)
        return true;
    // Solve for 1 case
    int leftheight = findHeight(root->left);
    int rightheight = findHeight(root->right);
    int diff = abs(leftheight-rightheight);
    bool curr_ans = (diff <= 1);
    // Remaining recursion will take care of 
    bool leftsubtree = isBalanced(root->left);
    bool rightsubtree = isBalanced(root->right);
    
    if(curr_ans && leftsubtree && rightsubtree)
        return true;
    else    
        return false;
}

int main(){
    Node* root;
    root = Buildtree();
    cout << "Balanced: " << isBalanced(root) << endl;
}