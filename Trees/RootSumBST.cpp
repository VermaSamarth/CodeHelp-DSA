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

void Traversal(Node* root, int& sum, int& low, int& high){
    if(root == nullptr)
        return;
    if(root->data >= low && root->data <= high)
        sum = sum + root->data;
    Traversal(root->left,sum,low,high);
    Traversal(root->right,sum,low,high);
    return;
}

int main(){
    Node* root;
    root = Buildtree();
    int low = 7;
    int high = 15;
    int sum = 0;
    Traversal(root,sum,low,high);
    cout << "Sum of the root bst: " << sum << endl;
}