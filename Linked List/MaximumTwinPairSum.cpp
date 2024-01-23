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

Node* findMiddle(Node* &head){
    if(head == nullptr || head->next == nullptr)
        return head;
    Node* slow = head;
    Node* fast = head->next;
    while(fast != nullptr){
        fast = fast->next;
        if(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow->next;
}

int pairSum(Node* &head) {
    if(head == nullptr)
        return 0;
    int sum = 0;
    int maxi = 0;
    stack<int> stk;
    Node* temp = findMiddle(head);
    while(temp != nullptr){
        stk.push(temp->data);
        temp = temp->next;
    }
    Node* nodes = head;
    Node* middle = findMiddle(head);
    while(nodes != middle){
        sum = nodes->data + stk.top();
        stk.pop();
        maxi = max(sum,maxi);
        nodes = nodes->next;
    }
    return maxi;
}

int main(){
    Node* head = nullptr;
    InsertStart(9,head);
    InsertStart(7,head);
    InsertStart(6,head);
    InsertStart(5,head);
    InsertStart(4,head);
    InsertStart(3,head);
    InsertStart(2,head);
    InsertStart(1,head);

    cout << "Linked List: " << endl;
    printList(head);
    int final = pairSum(head);
    cout << "Maximum Twin Pair Sum in the Linked List: " << final << endl;
}