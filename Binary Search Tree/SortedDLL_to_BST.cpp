#include<iostream>
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

Node* InsertIntoBST(Node* root, int data){
    if(root == nullptr){
        root = new Node(data);
        return root;
    }

    if(root->data < data){
        root->right = InsertIntoBST(root->right, data);
    }
    else{
        root->left = InsertIntoBST(root->left, data);
    }
    return root;
}

void CreateBST(Node* &root){
    int data;
    cin >> data;
    while(data != -1){
        root = InsertIntoBST(root, data);
        cin >> data;
    }
}

void InorderTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
    return;
}

void ConvertBST_to_DLL(Node* root, Node* &head){
    // Base case
    if(root == nullptr)
        return;
    
    ConvertBST_to_DLL(root->right, head);
    root->right = head;
    if(head != nullptr)
        head->left = root;
    
    head = root;
    ConvertBST_to_DLL(root->left, head);
    return;
}

Node* SortedLL_BST(Node* &head, int n){
    if(n <= 0 || head == nullptr)
        return nullptr;
    Node* left_subtree = SortedLL_BST(head, n - 1 - n/2);
    Node* root = head;
    root->left = left_subtree;
    head = head->right;
    root->right = SortedLL_BST(head, n/2);
    return root;
}

void PrintLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

int main(){
    Node* root = nullptr;
    int num;
    cout << "Enter the Node data to create the tree: " << endl;  
    CreateBST(root);
    Node* head = nullptr;
    ConvertBST_to_DLL(root, head);
    cout << "Printing the DLL: " << endl;
    PrintLL(head);
    Node* root2 = nullptr;
    root2 = SortedLL_BST(head, 7);
    cout << "Printing the BST: " << endl;
    InorderTraversal(root2);
    return 0;
}