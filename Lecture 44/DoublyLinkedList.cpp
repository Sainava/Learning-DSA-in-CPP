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

void InsertAtTail(Node * head,int data){
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
    temp->next->prev=newNode;
    newNode->prev=temp;
    temp->next=newNode;
}

void DeleteHead(Node * &head){
    if(head==NULL){
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
        return;
    }
    Node * temp=head;
    head=temp->next;
    head->prev=NULL;
    delete temp;
}

void deleteHead(Node * &head){
      if(head==NULL){
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
        return;
    }
    Node * temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    delete temp;
}


void deleteAtPosition(Node * &head,int pos){
    if(head==NULL){
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    if(pos==1){
        DeleteHead(head);
        return;
    }
    Node * temp=head;
    for(int i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL || temp->next==NULL){
        cout << "Position out of bounds, nothing to delete." << endl;
        return;
    }
    Node * toDelete=temp->next;
    if(toDelete->next==NULL){
        temp->next=NULL;
        delete toDelete;
        return;
    }
    toDelete->next->prev=temp;
    temp->next=toDelete->next;
    delete toDelete;
}
    
void deleteusingValue(Node * &head , int value){
    if(head==NULL){
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    if(head->data==value){
        DeleteHead(head);
        return;
    }
    Node * temp=head;
    while(temp!=NULL && temp->next->data!=value){
        temp=temp->next;
    }
    if(temp==NULL){
        cout << "Value not found, nothing to delete." << endl;
        return;
    }
    Node * toDelete=temp->next;
    if(toDelete->next==NULL){
        temp->next=NULL;
        delete toDelete;
        return; 
    }
    toDelete->next->prev=temp;  
    temp->next=toDelete->next;
    delete toDelete;
}

void deleteAll(Node * &head){
    while(head!=NULL){
        Node * temp=head;
        head=head->next;
        delete temp;
    }
    cout << "All nodes deleted." << endl;
}

void updateValue(Node * &head, int oldValue, int newValue){
    if(head==NULL){
        cout << "List is empty, nothing to update." << endl;
        return;
    }
    Node * temp=head;
    while(temp!=NULL){
        if(temp->data==oldValue){
            temp->data=newValue;
            cout << "Value updated successfully." << endl;
            return;
        }
        temp=temp->next;
    }
    cout << "Value not found, nothing to update." << endl;    
}
    

int main(){
    Node * head =new Node(10);
    InsertAtHead(head,1);
    printList(head);
    return 0;
}