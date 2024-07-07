#include<iostream>
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

bool FindAncestors(Node* root, int&target, vector<int>&ans){
    if(root == nullptr)
        return false;
    if(root->data == target)
        return true;
    if(FindAncestors(root->left, target, ans) || FindAncestors(root->right, target, ans)){
        ans.push_back(root->data);
        return true;
    }
    return false;
}

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

int main(){
    Node* root;
    root = Buildtree();
    int target;
    cin >> target;
    vector<int> ans;
    cout << "Ancestors : " ;
    FindAncestors(root, target, ans);
    for(auto it: ans)
        cout << it << " ";
    cout << endl;
}