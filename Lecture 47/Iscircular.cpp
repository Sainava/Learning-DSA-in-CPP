#include<iostream>
using namespace std;


class Node {
    public:
    int data;
    Node * next;

    Node (int data){
        this->data=data;
        this->next=NULL;
    }
};


void insertAtHead(Node * &head,int data){
    Node * newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        head->next=head;
        return;
    }
    
}

void insertAtPosition(Node * head,int pos,int data){
    Node * newNode=new Node(data);
    if(head==NULL){
        cout << "List is empty, cannot insert at position " << pos << "." << endl;
        return;
    }

    if(pos ==1){
        newNode->next=head;
        head=newNode;
        return;    
    }

    Node * temp=head->next;
    for(int i=1;i<pos-1 && temp->next!=head;i++){
        temp=temp->next;
    }
}
    

int main(){
   
    return 0;
}