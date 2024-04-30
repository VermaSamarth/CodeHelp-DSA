#include<iostream>
#include<queue>
#include<map>
#include<vector>
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

void PreorderTraversal(Node* root){
    if(root == nullptr)
        return ;
    cout << root->data << " ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
    return;
}

void topView(Node* root){
    // Base case
    if(root == nullptr)
        return;
    // map to store the top view data
    map<int,int> topNode;

    // For level order traversal
    queue<pair<Node*,int>> que;
    que.push(make_pair(root,0));
    while(!que.empty()){
        pair<Node*, int> temp = que.front();
        Node* frontNode = temp.first;
        que.pop();
        int hd = temp.second;
        // Checking if the corresponding top node already present in the map or not.
        if(topNode.find(hd) == topNode.end())
            topNode[hd] = frontNode->data;
        // Pushing the topNode->left into the queue
        if(frontNode->left != nullptr)
            que.push(make_pair(frontNode->left,hd - 1));
        // Pushing the topNode->right into the queue
        if(frontNode->right != nullptr)
            que.push(make_pair(frontNode->right,hd + 1));
    }
    for(auto it: topNode)
        cout << it.first << "->" << it.second << endl;
}

int main(){
    // map<int,vector<int>> ump;
    Node* root = BuildTree();
    cout << "Printing the Tree: ";
    PreorderTraversal(root);
    cout << endl << endl << "Top View of the tree: ";
    topView(root);
    cout << endl;
}