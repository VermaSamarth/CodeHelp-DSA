#include<iostream>
#include<vector>
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

Node* BuildTreeFromInorderPostorder(int inorder[], int postorder[],  int& postIndex,int size, int inorderStart, int inorderEnd, unordered_map<int,int>&ump){
    if(postIndex < 0 || inorderStart > inorderEnd)
        return nullptr;
    int element = postorder[postIndex--];
    Node* root = new Node(element);
    int position = ump[element];
    root->right = BuildTreeFromInorderPostorder(inorder, postorder, postIndex, size,  position + 1, inorderEnd, ump); 
    root->left = BuildTreeFromInorderPostorder(inorder, postorder, postIndex, size,  inorderStart, position - 1, ump);
    return root;

}

void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	//initially
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		//A
		Node* temp = q.front();
		//B
		q.pop();
		
		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}	
		}
		else {
			//C
			cout << temp->data << " ";
			//D
			if(temp -> left) {
				q.push(temp ->left);
			}
			if(temp ->right) {
				q.push(temp->right);
			}
		}
		
		
	}
}

int main(){
    int inorder[] = {40, 20, 10, 50, 30, 60};
    int postorder[]  = {40, 20, 50, 60, 30, 10};
    unordered_map<int,int> ump;
    int size = 6;
    int postIndex = size - 1;
    int inorderStart = 0;
    int inorderEnd = size-1;
    for(int i = 0; i < size; i++){
        int num = inorder[i];
        ump[num] = i;
    }
    Node* root = BuildTreeFromInorderPostorder(inorder, postorder, postIndex, size,  inorderStart, inorderEnd, ump);
    levelOrderTraversal(root);
}