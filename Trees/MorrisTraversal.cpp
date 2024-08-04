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

vector<int> InorderTraversal(Node* root){
    vector<int>ans;
    Node* current = root;
    while(current != nullptr){
        // If ROOT->LEFT is NULL then mark it as visited and move to right/
        if(current->left == nullptr){
            ans.push_back(current->data);
            current = current->right;
        }
        else{
            // Find the Inorder Predecessor
            Node* pred = current->left;
            while(pred->right != current && pred->right != nullptr){
                pred = pred->right;
            }

            // If PRED->RIGHT is NULL, then go left after establishing the link with current
            if(pred->right == nullptr){
                pred->right = current;
                current = current->left;
            }
            // LEFT is already visited, go RIGHT after visiting the current and remove the connection.
            else{
                pred->right = nullptr;
                ans.push_back(current->data);
                current = current->right;
            }
        }
    }
    return ans;
}

int main(){
    Node* root;
    root = Buildtree();
    vector<int> ans = InorderTraversal(root);
    cout << "Inorder Traversal: " ;
    for(auto it: ans)
        cout << it << " ";
    cout << endl;
}