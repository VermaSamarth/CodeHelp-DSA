#include<iostream>
#include<vector>
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

// Node* BuildTree(){

// }

int main(){
    Node* root;
    vector<int> arr = {10,20,30,40,50,-1,60,-1,70};
    // root = BuildTree()
}