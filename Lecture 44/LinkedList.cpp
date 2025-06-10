#include<iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node * next;
    
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

int main(){
   Node * head= new Node(10);

   cout << "Head data: " << head->data << endl;
   cout << "Head next: " << head->next << endl;
   return 0;
}