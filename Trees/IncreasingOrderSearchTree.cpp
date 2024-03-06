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

void Traversal(Node* root, queue<int>& nums){
    if(root == nullptr)
        return;
    Traversal(root->left,nums);
    nums.push(root->data);
    Traversal(root->right,nums);
    return;
}

Node* IncreasingOrder(queue<int>& nums){
    if(nums.empty())
        return nullptr;
    Node* newNode = new Node(nums.front());
    nums.pop();
    newNode->right = IncreasingOrder(nums);
    return newNode;
}

int main(){
    Node* root;
    root = BuildTree();
    queue<int> que;
    Traversal(root,que);
    Node* ans = IncreasingOrder(que);
    cout << "Ans: " << ans->data << endl;
}