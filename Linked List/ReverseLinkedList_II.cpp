#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = nullptr;
        }

        ~Node(){
            cout << "Node deleted successfully!!!" << endl;
        }
};

void InsertStart(int data, Node* &head){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return;    
}

void printList(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

Node* SortedList(Node* &head, int left, int right){
    if(head == nullptr || head->next == nullptr)
        return head;
    stack<Node*> stk;
    int middle = (right + left) / 2;
    Node* temp = head;
    
    int count = 1;
    while(count < middle){
        temp = temp->next;
        count++;
    }
    while(count <= right){
        stk.push(temp);
        temp = temp->next;
        count++;
    }
    
    count = 1;
    Node* position = head;
    while(count < left){
        position = position->next;
        count++;
    }
    while(count <= middle){
        swap(position->data, stk.top()->data);
        stk.pop();
        position = position->next;
        count++;
    }
    return head;
}


int main(){
Node* head = nullptr;
    InsertStart(6,head);
    InsertStart(5,head);
    InsertStart(4,head);
    InsertStart(3,head);
    InsertStart(2,head);
    InsertStart(1,head);
    cout << "Linked List before sorting: " << endl;
    printList(head);
    Node* final = SortedList(head,2,4);
    cout << "Linked list after sorting: " << endl;
    printList(final);
}