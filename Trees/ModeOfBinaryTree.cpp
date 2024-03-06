#include<iostream>
#include<unordered_map>
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

void CalculateMode(Node* root, unordered_map<int,int>& nums){
    if(root == nullptr)
        return;
    CalculateMode(root->left,nums);
    CalculateMode(root->right,nums);
    nums[root->data]++;
}
vector<int> findMode(Node* root) {
    unordered_map<int,int> nums;
    CalculateMode(root,nums);   
    int max = INT_MIN;
    vector<int> ans;
    for(auto it: nums){
        if(it.second > max)
            max = it.second;
    }
    for(auto it: nums){
       if(it.second == max)
            ans.push_back(it.first);
    }
    return ans;
}
int main(){
    Node* root;
    root = Buildtree();
    vector<int> ans = findMode(root);
    cout << "Modes of the tree are: ";
    for(auto it:ans)
        cout << it << " ";
    cout << endl;
}