#include<iostream>
#include<string>
#include<sstream>
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
    string input;
    getline(cin,input);
    istringstream iss(input);

    Node* root = nullptr;
    queue<Node**> q;
    q.push(&root);
    string val;
    while(iss>>val){
        Node** current = q.front();
        q.pop();

        if(val!="N"){
            *current= new Node(stoi(val));
            q.push(&((*current)->left));
            q.push(&((*current)->right));
        }
    }
    return root;
}
void levelOrderTraversal(Node* root) {
  if (root == nullptr) {
    return;
  }

  queue<Node*> q;
  q.push(root);

  while (!q.empty()) {
    Node* current = q.front();
    q.pop();

    cout << current->data << " ";

    if (current->left != nullptr) {
      q.push(current->left);
    }
    if (current->right != nullptr) {
      q.push(current->right);
    }
  }
}
int main(){
    string str;
    cin >> str;
    Node* root = BuildTree();
    levelOrderTraversal(root);
}