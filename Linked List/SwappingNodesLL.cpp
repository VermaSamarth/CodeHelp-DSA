#include<iostream>
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

int findLength(Node* &head){
    int count = 0;
    Node* temp = head;
    while(temp != nullptr){
        temp = temp->next;
        count++;
    }
    return count;
}

Node* SwappingKthNode(Node* &head, int k){
    if(head == nullptr)
        return head;
    int len = findLength(head);
    if(k > len)
        return head;
    int start = 1;
    int end = len - k;
    Node* temp1 = head;
    while(start < k){
        temp1 = temp1->next;
        start++;
    }
    Node* temp2 = head;
    start = 0;
    while(start < end){
        start++;
        temp2 = temp2->next;
    }
    swap(temp1->data, temp2->data);
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
    cout << "Linked List before Swapping: " << endl;
    printList(head);
    Node* final = SwappingKthNode(head,3);
    cout << "Linked list after swapping: " << endl;
    printList(final);
}