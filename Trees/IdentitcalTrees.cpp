12#include<iostream>
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

bool CheckIdentical(Node* &root1, Node* &root2){
    if(root1 == nullptr || root2 == nullptr)
        return false;
    queue<Node*> que1;
    queue<Node*> que2;
    que1.push(root1);
    que2.push(root2);
    while(!que1.empty() && !que2.empty()){
        Node* temp1 = que1.front();
        Node* temp2 = que2.front();
        if(temp1->data != temp2->data)
            return false;
        que1.pop();
        que2.pop();
        if(temp1->left != nullptr)
            que1.push(temp1->left);
        if(temp2->left != nullptr)
            que2.push(temp2->left);
        if (temp1->right != nullptr)
            que1.push(temp1->right);
        if(temp2->right != nullptr)
            que2.push(temp2->right);
    }
    if(!que1.empty() || !que2.empty())
        return false;
    return true;
}

int main(){
    Node* root1;
    Node* root2;
    
    root1 = Buildtree();
    root2 = Buildtree();

    bool ans = CheckIdentical(root1,root2);
    cout << ans << endl;
}