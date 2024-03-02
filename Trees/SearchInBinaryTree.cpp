#include<iostream>
#include<queue>
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

Node* searchTree(Node* root, int k){
    queue<Node*> que;
    if(root == nullptr)
        return nullptr;
    que.push(root);
    while(!que.empty()){
        Node* temp = que.front();
        que.pop();
        if(temp->data == k)
            return temp;
        if(temp->left != nullptr)
            que.push(temp->left);
        if(temp->right != nullptr)
            que.push(temp->right);
    }
    return nullptr;
}

int main(){
    Node* root;
    root = Buildtree();
    Node* ans = searchTree(root,20);
    if(ans != nullptr)
        cout << "Node & Tree found." << endl;
    else
        cout << "Node & Tree not found." << endl;
}