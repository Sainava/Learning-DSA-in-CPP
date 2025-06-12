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
}

void insertAtHead(Node * &head,int data ){
    if(head==NULL){
        head = new Node(data);
        return;
    }
    Node * newNode=new Node(data);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    Node * temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    head->prev=temp;
}

void insertAtTail(Node * &head, int data){
    if(head==NULL){
        head = new Node(data);
        return;
    }
    Node * newNode=new Node(data);
    Node * temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    newNode->next=head;
    head->prev=newNode;
}

void insertAtPosition(Node * &head, int pos, int data){
    if(pos==1){
        insertAtHead(head, data);
        return;
    }
    Node * newNode=new Node(data);
    Node * temp=head;
    for(int i=1; i<pos-1 && temp!=NULL; i++){
        temp=temp->next;
    }
    if(temp==NULL){
        cout << "Position out of bounds." << endl;
        delete newNode;
        return;
    }
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
}

void deleteAtHead(Node * &head){
    if(head==NULL){
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    if(head->next==head){ // Only one node
        delete head;
        head = NULL;
        return;
    }
    Node * temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    Node * toDelete=head;
    temp->next=head->next;
    head->next->prev=temp;
    head=head->next;
    delete toDelete;
}

void deleteAtTail(Node * &head){
    if(head==NULL){
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    if(head->next==head){ // Only one node
        delete head;
        head = NULL;
        return;
    }
    Node * temp=head;
    while(temp->next->next!=head){
        temp=temp->next;
    }
    Node * toDelete=temp->next;
    temp->next=head;
    head->prev=temp;
    delete toDelete;
}

void deleteAtPosition(Node * &head, int pos){
    if(head==NULL){
        cout << "List is empty, nothing to delete." << endl;
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
    for(int i=1; i<pos-1 && temp!=head; i++){
        temp=temp->next;
    }
    Node * toDelete=temp->next;
    temp->next=toDelete->next;
    toDelete->next->prev=temp;
    delete toDelete;
}

void deleteUsingValue(Node * &head, int value){
    if(head==NULL){
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    Node * temp=head;
    do {
        if(temp->data == value){
            if(temp == head) {
                deleteAtHead(head);
                return;
            } else if(temp->next == head) {
                deleteAtTail(head);
                return;
            } else {
                Node * toDelete=temp;
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                delete toDelete;
                return;
            }
        }
        temp = temp->next;
    } while(temp != head);
    cout << "Value not found, nothing to delete." << endl;
}

void update(Node * &head,int oldValue,int newValue ){
    if(head==NULL){
        cout << "List is empty, nothing to update." << endl;
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
    cout << "Value not found, nothing to update." << endl;

}

int main(){
   cout << "Hello, Circular Linked List!" << endl;
   Node* head = NULL;
   insertAtHead(head, 10);
   insertAtHead(head, 20);
   insertAtHead(head, 30);

}