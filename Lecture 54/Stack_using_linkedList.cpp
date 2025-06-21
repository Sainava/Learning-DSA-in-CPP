#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node * next;

        Node (int data){
            this->data=data;
            next=NULL;
        }
};

// In the following pop operation is O(n) because we traverse the linked list to find the top element.
/*
class Stack { 
    public:
        Node * head;
        Node * top;
        

        Stack(){
            head=NULL;
            top=NULL;
        }

        void push(int data){
            Node * newNode = new Node(data);
            if(head==NULL){
                head=newNode;
                top=newNode;
                return;
            }
            top->next=newNode;
            top=newNode;
        }

        int pop(){
            if(head==NULL){
                std::cout << "Stack Underflow: " << " ";
                return -1;
            }
            int data=top->data;
            if(head==top){
                delete top;
                head=NULL;
                top=NULL;
                return data;
            }
            Node * temp=head;
            while(temp->next!=top){
                temp=temp->next;
            }
            top=temp;
            delete temp->next;
            temp->next=NULL;
            return data;
        }


        int peek(){
            if(head==NULL){
                std::cout << "Stack is empty: " << " ";
                return -1;
            }
            return top->data;
        }

        bool empty(){
            return head==NULL;
        }

        int size(){
            int count=0;
            if(head==NULL){
                return count;
            }
            Node * temp=head;
            while(temp!=NULL){
                count++;
                temp=temp->next;
            }
            return count;
        }

        // The following is not great since it prints in FIFO order, not LIFO order.
        void print(){
            if(head==NULL){
                std::cout << "Stack is empty" << std::endl;
                return;
            }
            Node * temp=head;
            while(temp!=NULL){
                std::cout << temp->data << " ";
                temp=temp->next;
            }
            std::cout << std::endl;
        }
};
*/

// Optimized Stack implementation with O(1) push, pop, and peek operations
class Stack {
    public:
        Node * head ; // we used word head for simplicity, it can be named top as well.

        Stack(){
            head=NULL;
        }

        void push(int data){
            Node * newNode= new Node(data);
            if(head==NULL){
                head=newNode;
                return;
            }
            newNode->next=head;
            head=newNode;
        }

        int pop(){
            if(head==NULL){
                std::cout << "Stack Underflow: " << " ";
                return -1;
            }
            int data=head->data;
            Node * temp=head;
            head=head->next;
            delete temp;
            return data;
        }

        int peek(){
            if(head==NULL){
                std::cout << "Stack is empty: " << " ";
                return -1;
            }
            return head->data;
        }

        bool empty(){
            return head==NULL;
        }

        int size(){
            int count=0;
            Node * temp=head;
            while(temp!=NULL){
                count++;
                temp=temp->next;
            }
            return count;
        }

        void print(){
            if(head==NULL){
                std::cout << "Stack is empty" << std::endl;
                return;
            }
            Node * temp=head;
            while(temp!=NULL){
                std::cout << temp->data << " ";
                temp=temp->next;
            }
            std::cout << std::endl;
        }


        ~Stack(){
            while(head != NULL){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }


};

using namespace std;

int main(){
   Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.print(); 
    cout << "Top element: " << s.peek() << endl; 
    cout << "Stack size: " << s.size() << endl; 
    s.pop();
    s.print();  
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;
    return 0;
}