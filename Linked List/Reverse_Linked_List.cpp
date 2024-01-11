#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        ~Node(){
            cout << "Node has been deleted....." << endl;
        }
};

void InsertEnd(int data, Node* &head, Node* &tail){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

Node* reverseList(Node* &left, Node* &curr){
    if(curr == NULL)
        return left;
    Node* right = curr->next;
    curr->next = left;
    return reverseList(curr,right);
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

// Another logic from the leetcode reverse the string question.

// ListNode* reverseList(ListNode* head) {
//         ListNode* left = NULL;
//         ListNode* curr = head;
//         ListNode* right ;
//         while(curr != NULL){
//             right = curr->next;
//             curr->next = left;
//             left = curr;
//             curr = right;
//         }
//         return left;
//     }

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    InsertEnd(50,head,tail);
    InsertEnd(60,head,tail);
    InsertEnd(70,head,tail);
    InsertEnd(80,head,tail);
    InsertEnd(90,head,tail);
    InsertEnd(100,head,tail);
    cout << "Printing the list: " << endl;
    printList(head);

    Node* left = NULL;
    Node* curr = head;
    head = reverseList(left,curr);
    cout << "Printing the reverse list: " << endl;
    printList(head);
}