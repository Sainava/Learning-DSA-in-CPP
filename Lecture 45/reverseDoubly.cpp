#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int data){
            this->data=data;
            this->prev=NULL;
            this->next=NULL;
        }
};

void printList(Node * &head){
    if(head==NULL){
        cout << "List is empty." << endl;
        return;
    }
    Node*temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
}

void InsertAtHead(Node * &head,int data){
    if(head==NULL){
        head =new Node(data);
        return;
    }

    Node* temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void InsertAtTail(Node * &head,int data){
     Node * newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    if(head->next==NULL){
        head->next=newNode;
        newNode->prev=head;
        return;
    }

    Node * temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void InsertAtPosition(Node * &head,int pos ,int data){
    if(pos==1){
        InsertAtHead(head, data);
        return;
    }
    Node * newNode=new Node(data);
    Node * temp=head;
    for(int i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        cout << "Position out of bounds, inserting at tail." << endl;
        InsertAtTail(head, data);
        return;
    }
    newNode->next=temp->next;
    if (temp->next != NULL) {
    temp->next->prev = newNode;
    }
    newNode->prev=temp;
    temp->next=newNode;
}


void reverseList(Node * &head){
    if(head==NULL || head->next==NULL){
        
    }
    Node * current =head;
    Node * prev=NULL;
    Node * forward=head;
    while(current !=NULL){
        forward=current->next;
        current->next=prev;
        current->prev=forward;
        prev=current;
        current=forward;
    }
    head=prev;
}

int main(){
    Node * head =NULL;
    InsertAtPosition(head,1,10);
    InsertAtPosition(head,2,20);
    InsertAtPosition(head,3,30);
    InsertAtPosition(head,4,40);
    InsertAtPosition(head,5,50);
    printList(head);
    cout << endl;
    reverseList(head);
    printList(head);
    cout << endl;
    return 0;
}