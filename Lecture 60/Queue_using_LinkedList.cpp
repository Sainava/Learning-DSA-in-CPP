#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;

        Node(int data){
            this->data = data;
            this->next = NULL;  
        }
};

class Queue{
public:
    Node * front;
    Node * rear;

    Queue(){
        front = NULL;
        rear = NULL;
    }

    void enqueue(int data){
        Node * newNode=new Node(data);

        // If the queue is empty, both front and rear point to the new node
        if(front==NULL){
            front= newNode;
            rear=newNode;
        }else{
            rear->next=newNode;
            rear=newNode; // Move rear to the new node
        }
    }

    int dequeue(){
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
            return -1; // Indicating queue is empty
        }

        int data = front->data;
        Node * temp = front;
        front = front->next;

        // If the queue becomes empty after dequeue, set rear to NULL
        if(front == NULL){
            rear = NULL;
        }

        delete temp; // Free the memory of the dequeued node
        return data;
    }

    int Front(){
        if(front == NULL){
            cout<<"Queue is empty"<<endl;
            return -1; // Indicating queue is empty
        }
        return front->data; // Return the data of the front node
    }

    bool isEmpty(){
        return front == NULL; // If front is NULL, the queue is empty
    }
    void display(){
        if(front == NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }

        Node * temp = front;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    ~Queue(){
        while(front!=NULL){
            Node * temp=front;
            front = front->next;
            delete temp; // Free the memory of the node
        }
        rear = NULL; // Set rear to NULL after deleting all nodes
    }   

};





int main(){

    Queue q;
    int n;
    cout << "Enter the number of elements to enqueue: ";
    cin >> n;
    cout << "Enter the elements to enqueue: ";
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.enqueue(x);
    }   

    cout << "Queue after enqueue operations: ";
    q.display();    

    cout << "Front element: " << q.Front() << endl;
    cout << "Dequeue operation: " << q.dequeue() << endl;
    cout << "Queue after dequeue operation: ";
    q.display();    
   
    return 0;
}