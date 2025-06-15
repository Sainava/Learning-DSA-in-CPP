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

    // ~Node(){
    //     int value = this ->data;
    //     if(this->next!=NULL){
    //         delete next;
    //         next=NULL;
    //     }
    //     // cout << "Memory freed for node with data: " << value << endl;
    // }
};



void AddatTail(Node * &tail,int data){
    Node * newNode=new Node(data);
    if(tail==NULL){
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

void deleteHead(Node * Head){
    if(Head==NULL){
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    Node * temp=Head;
    Head=Head-> next;
    delete temp;
}

void deleteTail(Node * Head){
    if(Head==NULL){
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    Node * temp=Head;
    if(temp->next==NULL){
        delete temp;
        Head=NULL;
        return;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
}
void deleteAtPosition(Node * & Head,int pos){
    if(Head==NULL){
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    if(pos==1){
        Node * temp=Head;
        Head=Head->next;
        delete temp;
        return;
    }

    Node * temp=Head;
    for(int i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }    
    if(temp==NULL || temp->next==NULL){
        cout << "Position out of bounds, nothing to delete." << endl;
        return;
    }

    Node * toDelete=temp->next;
    temp->next=toDelete->next;
    delete toDelete;
}

void deleteusingValue(Node * Head,int value ){
    if(Head==NULL){
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    if(Head->data==value){
        Node * temp=Head;
        Head=Head->next;
        delete temp;
        return;
    }
    Node * temp=Head;
    while(temp->next!=NULL && temp->next->data!=value){
        temp=temp->next;
    }
    if(temp->next==NULL){
        cout << "Value not found, nothing to delete." << endl;
        return;
    }
    Node * toDelete=temp->next;
    temp->next=toDelete->next;
    delete toDelete;
}

void  deleteList(Node * &Head){
    if(Head==NULL){
        cout << "List is already empty." << endl;
        return;
    }
    Node * temp;
    while(Head != NULL){
        temp = Head;
        Head = Head->next;
        delete temp;
    }
    cout << "List deleted successfully." << endl;
}

void updateValue(Node * Head, int oldValue, int newValue) {
    if (Head == NULL) {
        cout << "List is empty, nothing to update." << endl;
        return;
    }
    Node * temp = Head;
    while(temp!=NULL){
        if(temp->data==oldValue){
            temp->data=newValue;
            cout << "Value updated successfully." << endl;
            return; 
        }
    }
    if(temp==NULL){
        cout << "Value not found, nothing to update." << endl;
        return;
    }
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

Node *removeDuplicates(Node *head)
{
    if(head == NULL) return head;

    Node *temp = head;

    while(temp != NULL){
        Node *inner = temp;

        while(inner->next != NULL){
            if(inner->next->data == temp->data){
                Node *toDelete = inner->next;
                inner->next = toDelete->next;
                delete toDelete;
            } else {
                inner = inner->next;
            }
        }

        temp = temp->next;
    }

    return head;     
}


int main(){
   Node * head= new Node(10);

//    cout << "Head data: " << head->data << endl;
//    cout << "Head next: " << head->next << endl;
//    InsertAtHead(head,1);
//    InsertAtTail(head,20);
//    printList(head);
//    InsertAtPosition(head, 15, 3);
//     printList(head);

//    //isCircular(head) ? cout << "The linked list is circular." << endl : cout << "The linked list is not circular." << endl;
//    isCircularUsingMap(head) ? cout << "The linked list is circular using map." << endl : cout << "The linked list is not circular using map." << endl;

//    deleteHead(head); 
     InsertAtPosition(head, 5, 2);
     InsertAtPosition(head, 15, 3);
    InsertAtPosition(head, 15, 4);
    InsertAtPosition(head, 15, 5);
    InsertAtPosition(head, 25, 6);
    InsertAtPosition(head, 25, 7);
    cout << "Linked List after insertions: ";
    printList(head);

    head=removeDuplicates(head);
    cout << "Linked List after removing duplicates: ";
    printList(head);



   return 0;
}