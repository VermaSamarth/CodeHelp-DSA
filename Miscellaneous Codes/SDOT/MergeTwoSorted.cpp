// You are using GCC
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};

void InsertNode(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head == nullptr){
        head = tail = newNode;
        head->next = nullptr;
    }
    else{
        tail->next = newNode;
        tail = tail->next;
    }
}

Node* mergeSortedList(Node* head1, Node* head2){
    if(head1 == nullptr)
        return head2;
    if(head2 == nullptr)
        return head1;
    Node* ans = nullptr;
    Node* tail = nullptr;
    while(head1 != nullptr && head2 != nullptr){
        if(head1->data <= head2->data){
            // Node* newNode = new Node(head1->data);
            InsertNode(ans,tail,head1->data);
            head1 = head1->next;
        }
        else{
            // Node* newNode = new Node(head2->data);
            InsertNode(ans,tail,head2->data);
            head2 = head2->next;
        }
    }
    while(head1 != nullptr){
        // Node* newNode = new Node(head1->data);
        InsertNode(ans,tail,head1->data);
        head1 = head1->next;
    }
    while(head2 != nullptr){
        // Node* newNode = new Node(head2->data);
        InsertNode(ans,tail,head2->data);
        head2 = head2->next;
    }
    return ans;
}

void printList(Node* list){
    while(list != nullptr){
        cout << list->data << "->";
        list = list->next;
    }
    cout << "NULL" << endl;
}

int main(){
    Node* head1 = nullptr;
    Node* tail1 = nullptr;
    int len1, len2;
    cin >> len1;
    int data;
    // Inserting the elements of list1
    for(int i = 0; i < len1; i++){
        cin >> data;
        InsertNode(head1,tail1,data);
    }
    Node* head2 = nullptr;
    Node* tail2 = nullptr;
    cin >> len2;
    // Inserting the elements of list2
    for(int i = 0; i < len2; i++){
        cin >> data;
        InsertNode(head2,tail2,data);
    }
    printList(head1);
    printList(head2);
    Node* ans = mergeSortedList(head1,head2);
    printList(ans);
}