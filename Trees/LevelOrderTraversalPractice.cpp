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

void PrintLevelOrder(Node* root){
    queue<Node*> level;
    level.push(root);
    while(!level.empty()){
        Node* temp = level.front();
        level.pop();
        cout << temp->data << " ";
        if(temp->left != nullptr)
            level.push(temp->left);
        if(temp->right != nullptr)
            level.push(temp->right);
    }
}

void LevelOrderTraversal(Node* root){
    queue<Node*> level;
    level.push(root);
    level.push(nullptr);
    while(!level.empty()){
        Node* temp = level.front();
        level.pop();
        if(temp == nullptr){
            cout << endl;
            if(!level.empty())
                level.push(nullptr);
        }
        else{
            cout << temp->data << " ";
            if(temp->left != nullptr)
                level.push(temp->left);
            if(temp->right != nullptr)
                level.push(temp->right);
        }
    }
}

int main(){
    Node* root;
    root = Buildtree();
    cout << "Level Order Travesal of the inputted tree is: " << endl;
    // PrintLevelOrder(root);
    LevelOrderTraversal(root);
}