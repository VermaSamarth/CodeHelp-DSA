#include<iostream>
#include<queue>
#include<unordered_map>
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

void getNums(Node* root, unordered_map<int,int>& nums){
        if(root == nullptr)
            return;
        nums[root->data]++;
        getNums(root->left,nums);
            // nums.push_back(root->data);
        getNums(root->right,nums);
        return;
    }
    bool isUnivalTree(Node* root) {
        unordered_map<int,int> nums;
        getNums(root,nums);
        cout << "Ans:" << endl;
        if(nums.size() != 1)
            return false;
        return true;
    }

int main(){
    Node* root;
    root = Buildtree();
    bool ans = isUnivalTree(root);
    cout << ans << endl;
}