#include<iostream>
#include<stack>
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

Node* reverseList(Node* &head){
    Node* current = head;   
    Node* previous = nullptr;
    Node* forward ;
    while(current != nullptr){
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }
    return previous;
}

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
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

Node* removeNode(Node* &head){
    stack<Node*> stk;
    Node* temp = head;
    stk.push(temp);
    temp = temp->next;
    while(temp != nullptr){
        while(stk.empty() == false && temp->data > stk.top()->data){
            cout << "Popping: " << stk.top()->data << endl;
            stk.pop(); 
        }
        if(stk.empty()){
            head = temp;
        }
        else{
            stk.top()->next = temp;
        }
        if(stk.empty() || temp->data <= stk.top()->data){
            stk.push(temp);
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    Node* head = nullptr;
    InsertStart(50,head); 
    InsertStart(40,head);
    InsertStart(60,head);
    InsertStart(30,head);
    InsertStart(70,head);
    InsertStart(20,head);
    InsertStart(10,head);
    cout << "Linked List: " << endl;
    printList(head);
    Node* addr = removeNode(head);
    cout << "Linked List: " << endl;
    printList(addr);
}