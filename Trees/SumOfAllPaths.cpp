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

void FindTreeSum(Node* root,vector<int>& numbers, int num){
    if(root == nullptr){
        return;
    }
    num = (num * 10) + (root->data);
    FindTreeSum(root->left,numbers,num);
    FindTreeSum(root->right,numbers,num);
    if(root->left == nullptr && root->right == nullptr)
        numbers.push_back(num);
    return;
}

int main(){
    Node* root;
    root = Buildtree();
    cout << "Tree is successfully built" << endl;
    vector<int> numbers;
    int num = 0;
    FindTreeSum(root,numbers,num);
    int sum = 0;
    cout << "Printing the numbers: ";
    for(auto i:numbers){
        cout << i << " ";
        sum = sum + i;
    }
    cout << endl << "Sum of the numbers: " << sum << endl;
}