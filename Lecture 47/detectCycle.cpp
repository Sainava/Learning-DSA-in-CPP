#include<iostream>
#include<map>
using namespace std;

class Node {
    public: 
        int data;
        Node * next;
    
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node(){
        int value = this ->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout << "Memory freed for node with data: " << value << endl;
    }
};

void AddatTail(Node * &head,Node * &tail,int data){
    Node * newNode=new Node(data);
    if(head==NULL && tail==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    if(head==tail){
        head->next=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;

}

void printList(Node * &Head){
    Node * temp=Head;
    while(temp !=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}

void InsertAtHead(Node* &Head,int data){
    if(Head==NULL){
        Head=new Node(data);
        return;
    }
    Node * newNode=new Node(data);
    newNode->next=Head;
    Head=newNode;
}

void InsertAtTail(Node* &Head,int data){
    Node * newNode=new Node(data);
    if(Head==NULL){
        Head=newNode;
        return;
    }
    Node * temp=Head;
    while(temp->next!=NULL){

        temp=temp->next;
    }
    temp->next=newNode;
}

void InsertAtPosition(Node* &Head,int data,int pos){
    if(pos==0){
        InsertAtHead(Head,data);
        return;
    }
    Node* newNode=new Node(data);
    Node* temp= Head;
    for(int i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        cout << "Position out of bounds, inserting at tail instead." << endl;
        InsertAtTail(Head, data);
        return;
    }

    newNode->next=temp->next;

    temp->next=newNode;
}

bool detectLoop(Node * head){
    if(head==NULL){
        return false;
    }
    map<Node*, bool> visited;
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

Node*  floydCycleDetection(Node * head){
    if(head==NULL){
        return NULL;
    }

    Node * slow=head;
    Node * fast=head;
    while(slow!=NULL  and  fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        // They will meet at some point if there is a cycle,need not be at the start of the cycle
        slow=slow->next;
        if(slow==fast){
            return slow;
        }
    }

    return NULL;         
}


Node * getStartingNode(Node * head){
    if(head==NULL){
        return NULL;
    }
    Node * intersection =floydCycleDetection(head);
    if(intersection==NULL){
        return NULL;
    }
    Node * slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}


void removeCycle(Node * head){
    if(head==NULL){
        return;
    }

    Node * startOfloop =getStartingNode(head);
    Node * temp=startOfloop;

    while(temp->next!=startOfloop){
        temp=temp->next;
    }
    temp->next=NULL; // Break the cycle
    cout << "Cycle removed from the linked list." << endl;
}


int main(){

    Node * head=NULL;
    InsertAtHead(head,10);
    Node * tail=head;
    AddatTail(head,tail,20);
    AddatTail(head,tail,30);
    AddatTail(head,tail,40);
    AddatTail(head,tail,50);
    printList(head);
    tail->next=head->next->next;
    //printList(head);
    //delete head;

    //detectLoop(head) ? cout << "Loop detected in the linked list." << endl : cout << "No loop detected in the linked list." << endl;
    floydCycleDetection(head)==NULL ? cout << "No cycle detected in the linked list." << endl : cout << "Cycle detected in the linked list." << endl;

    Node * startingNode = getStartingNode(head);
    if(startingNode != NULL){
        cout << "Cycle starts at node with data: " << startingNode->data << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    removeCycle(head);
    printList(head);
    

    return 0;
}