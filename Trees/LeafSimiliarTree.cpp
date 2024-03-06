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

void Traversal(Node* root, queue<int>& nodes){
    if(root == nullptr)
        return;
    Traversal(root->left, nodes);
    Traversal(root->right, nodes);
    if(root->left == nullptr && root->right == nullptr)
        nodes.push(root->data);
    return;
}

void printQueue(queue<int> nodes){
    while(!nodes.empty()){
        cout << nodes.front() << " ";
        nodes.pop();
    }
    cout << endl;
}

bool leafSimilar(Node* root1, Node* root2) {
    queue<int> que1;
    queue<int> que2;
    Traversal(root1,que1);
    Traversal(root2,que2);
    // printQueue(que1);
    // printQueue(que2);
    if(que1.size() != que2.size())
        return false;
    else{
        while(!que1.empty() && !que2.empty()){
            int num1 = que1.front();
            int num2 = que2.front();
            que1.pop();
            que2.pop();
            if(num1 != num2)
                return false;
        }
        if(que1.size() != que2.size())
            return false;
        return true;
    }          
}

int main(){
    Node* root1;
    Node* root2;
    root1 = Buildtree();
    root2 = Buildtree();
    bool ans = leafSimilar(root1,root2);
    cout << "Ans: " << ans << endl;
}