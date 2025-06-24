#include<iostream>
using namespace std;

class KQueue{
    public:
    int *arr;
    int *front;
    int *rear;
    int *next;
    int size, k;
    int freeSpot;

    //Constructor to initialize the KQueue
    KQueue(int n,int k){
        this->k=k;
        size= n;
        arr=new int[size];
        front=new int[k];
        rear=new int[k];
        next=new int[size];
        freeSpot=0;

        for(int i=0;i<k;i++){
            front[i]=-1;
            rear[i]=-1;
        }

        for(int i=0;i<size-1;i++){
            next[i]=i+1;
        }

        next[size-1]=-1;
    }

    //qn shows the queue number starting from 1,2,3 and so on
    void enqueue(int data,int qn){

        // Step 1 : check if  Queue is full
        if(freeSpot==-1){
            cout << "Queue Overflow" << endl;
            return;
        }
        
        // Step 2: Find the next free spot
        int index=freeSpot;

        //Step 3: Update the freeSpot
        freeSpot=next[index];

        // Step 4: Insert the element in the array
        // First element of the queue is to be inserted
        if(front[qn-1]==-1){
            front[qn-1]=index;

        }else{
            next[rear[qn-1]]=index;
        }

        // Step 5: Update the rear of that queue and the  next of the current index
        rear[qn-1]=index;
        next[rear[qn-1]]=-1; // or nexrt[index]=-1; // Basically last element of the queue will point to -1

        // Step 6: Insert the data in the array
        arr[index]=data;

        cout << "Inserted " << data << " in queue " << qn << endl;
            
    }
        
    int deque(int qn){
        // Step 1: Check if the queue is empty
        if(front[qn-1]==-1){
            cout << "Queue Underflow" << endl;
            return -1; // or throw an exception
        }

        // Step 2: Get the index of the front element
        int index=front[qn-1];

        // Step 3: Update the front of the queue
        front[qn-1]=next[index]; // Update the front of the queue
        
        //Step 4: Update the next of the current index
        next[index]=freeSpot; 

        // Step : Update the freeSpot
        freeSpot=index;

        // Step 6: Return the dequeued element
        return arr[index];

    }

    void print(int qn){
        if(front[qn-1]==-1){
            cout << "Queue " << qn << " is empty" << endl;
            return;
        }

        cout << "Elements in queue " << qn << ": ";
        int index =front[qn-1];
        while(index!=-1){
            cout << arr[index] << " ";
            index=next[index]; // Move to the next element in the queue
        }cout << endl;
    }

};

int main(){
   //KQueue *kq=new KQueue(10, 3); // Create a KQueue with 10 elements and 3 queues

   KQueue kq(10,3);

    kq.enqueue(10, 1);
    kq.enqueue(20, 1);

    kq.enqueue(30, 2);
    kq.enqueue(40, 2);

    kq.enqueue(50, 3);
    kq.enqueue(60, 3);

    kq.print(1);
    kq.print(2);
    kq.print(3);

    cout << "Dequeued from queue 1: " << kq.deque(1) << endl;
    cout << "Dequeued from queue 2: " << kq.deque(2) << endl;
    cout << "Dequeued from queue 3: " << kq.deque(3) << endl;


    kq.print(1);
    kq.print(2);
    kq.print(3);
    return 0;
}