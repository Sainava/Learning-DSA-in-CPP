#include<iostream>
#include<map>
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


void printList(Node * & head){
    if(head==NULL){
        cout << "List is empty." << endl;
        return;
    }
    Node * temp=head;
    do{
        cout << temp->data << " ";
        temp=temp->next;
    }while(temp!=head);
    cout << endl;
}
    

void insertAtHead(Node * &head,int data){
    Node * newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        head->next=head;
        return;
    }
    Node*temp=head->next;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
    head=newNode;
    return;
}

void insertAtTail(Node * &head,int data){
    Node * newNode = new Node(data);
    if(head==NULL){
        insertAtHead(head, data);
        return;
    }

    Node * temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
    return;
}

void insertAtPosition(Node * &head,int pos,int data){
    Node * newNode=new Node(data);
    if(head==NULL){
        //"List is empty,inserting at postion 1"
        insertAtHead(head, data);
        return;
    }

    if(pos ==1){
        insertAtHead(head, data);
        return;    
    }

    Node * temp=head;
    for(int i=1;i<pos-1 && temp->next!=head;i++){
        temp=temp->next;
    }
    if(temp->next==head && pos>1){
       //" Inserting at the end." 
        insertAtTail(head, data);
        return;
    }

    newNode->next=temp->next;
    temp->next=newNode;
    return;

}

bool isCircular(Node * head){
    if(head==NULL){
        return false;
    }
    Node * temp=head;
    while(temp->next!=NULL && temp->next!=head){
        temp=temp->next;

    }
    return temp->next==head;
}

bool isCircularUsingMap(Node * head){
    if(head==NULL){
        return false;
    }
    map<Node* ,bool> visited;
    Node * temp=head;
    while(temp!=NULL){
        if(visited[temp]){
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

int main(){
    Node * head = NULL;
    insertAtPosition(head, 1, 10);
    insertAtPosition(head, 2, 15);
    insertAtPosition(head, 3, 20);
    insertAtPosition(head, 2, 12);
    insertAtPosition(head, 5, 25);
    printList(head);

    //isCircular(head) ? cout << "The linked list is circular." << endl : cout << "The linked list is not circular." << endl;
    isCircularUsingMap(head) ? cout << "The linked list is circular using map." << endl : cout << "The linked list is not circular using map." << endl;
   
    return 0;
}