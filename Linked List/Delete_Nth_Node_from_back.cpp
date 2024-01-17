#include<iostream>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode* next;

        ListNode(int data){
            this->data = data;
            this->next = nullptr;
        }
};

void InsertStart(int data, ListNode* &head){
    if(head == NULL){
        ListNode* newNode = new ListNode(data);
        head = newNode;
        return;
    }
    ListNode* newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
    return;    
}

// Function to print the linked list
void printList(ListNode* &head){
    ListNode* temp = head;
    
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

    int findLength(ListNode* &head){
        ListNode* temp = head;
        int count = 0; 
        while(temp != nullptr){
            temp = temp->next;
            count++;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int &n) {
        ListNode* temp = head;
        int position = findLength(head) - n;
        int count = 1;
        while(count < position){
            temp = temp->next;
            ++count;
        }    
        if(position == 0){
            temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
            return head;
        }
        ListNode* curr = temp->next;
        if(temp->next != nullptr)
            temp->next = temp->next->next;
        else
            temp->next = nullptr;
        delete curr;
        return head;
    }
    
int main(){
    ListNode* head = nullptr;
    InsertStart(10,head);
    InsertStart(20,head);
    InsertStart(30,head);
    InsertStart(40,head);
    InsertStart(50,head);
    InsertStart(60,head);
    cout << "Printing the linked list: " << endl;
    printList(head);

    int pos = 4;
    removeNthFromEnd(head,pos);
    cout << "Printing the linked list after deletion: " << endl;
    printList(head);

}