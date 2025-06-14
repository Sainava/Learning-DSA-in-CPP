#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int data) {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};

void printList(Node * & head){
    if(head==NULL){
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);
    cout << endl;
}

void insertAtHead(Node * &head,int data ){
    Node * newNode=new Node(data);
    if(head==NULL){
        newNode->next=newNode;
        newNode->prev=newNode;
        head = newNode;
        return;
    }
    Node* tail = head->prev;
    newNode->next=head;
    newNode->prev=tail;
    tail->next=newNode;
    head->prev=newNode;
    head=newNode;
}

void insertAtTail(Node * &head, int data){
    if(head==NULL){
        insertAtHead(head, data);
        return;
    }
    Node * newNode=new Node(data);
    Node * tail=head->prev;
    newNode->next=head;
    newNode->prev=tail;
    tail->next=newNode;
    head->prev=newNode;
}

void insertAtPosition(Node * &head, int pos, int data){
    if(pos==1){
        insertAtHead(head, data);
        return;
    }
    Node * temp=head;
    for(int i=1; i<pos-1 && temp->next!=head; i++){
        temp=temp->next;
    }
    Node * newNode=new Node(data);
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next->prev=newNode;
    temp->next=newNode;
}

void deleteAtHead(Node * &head){
    if(head==NULL){
        return;
    }
    if(head->next==head){
        delete head;
        head = NULL;
        return;
    }
    Node* tail = head->prev;
    Node* toDelete = head;
    head = head->next;
    head->prev = tail;
    tail->next = head;
    delete toDelete;
}

void deleteAtTail(Node * &head){
    if(head==NULL){
        return;
    }
    if(head->next==head){
        delete head;
        head = NULL;
        return;
    }
    Node* tail = head->prev;
    Node* newTail = tail->prev;
    newTail->next = head;
    head->prev = newTail;
    delete tail;
}

void deleteAtPosition(Node * &head, int pos){
    if(head==NULL){
        return;
    }
    int len=1;
    Node * temp=head->next;
    while(temp!=head){
        len++;
        temp=temp->next;
    }
    pos =(pos-1)%len +1;
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    temp=head;
    for(int i=1; i<pos-1 && temp->next!=head; i++){
        temp=temp->next;
    }
    Node * toDelete=temp->next;
    temp->next=toDelete->next;
    toDelete->next->prev=temp;
    delete toDelete;
}

void deleteUsingValue(Node * &head, int value){
    if(head==NULL){
        return;
    }
    Node * temp=head;
    do {
        if(temp->data == value){
            if(temp == head) {
                deleteAtHead(head);
                return;
            } else if(temp->next == head && temp == head->prev) {
                deleteAtTail(head);
                return;
            } else {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                delete temp;
                return;
            }
        }
        temp = temp->next;
    } while(temp != head);
}

void update(Node * &head,int oldValue,int newValue ){
    if(head==NULL){
        return;
    }
    Node * temp=head;
    do {
        if(temp->data == oldValue){
            temp->data = newValue;
            return;
        }
        temp = temp->next;
    } while(temp != head);
}

int main(){
   Node* head = NULL;
   insertAtHead(head, 10);
   insertAtHead(head, 20);
   insertAtHead(head, 30);
   printList(head);
}
