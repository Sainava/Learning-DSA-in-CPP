#include<iostream>
#include<queue>
using namespace std;


// Heap is a complete binary tree which satisfies the heap property
// In a max heap, the value of each node is greater than or equal to the values of its children
// In a min heap, the value of each node is less than or equal to the values of its children

class Heap{
    public :
        int arr[100];
        int size;// basically the number of elements in the heap and the last index of the array

        Heap(){
            size=0;
        }

        void insert(int data){
            size++;

            arr[size]=data;
            int index=size;

            while(index>1){
                int parent=index/2;

                if(arr[parent] < arr[index]){
                    swap(arr[parent],arr[index]);
                    index =parent;
                }else{
                    return ;
                }
            }
        }

        void print(){
            for(int i=1;i<=size;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }


        void deletefromheap(){ // basically delete the root node
            if(size==0){
                cout << "Heap is empty" << endl;
                return;
            }

            arr[1]=arr[size];
            size--; //treat this as deletion of the last element ,here the root

            int index=1;

            while(true){
                int left = 2*index;  // In 1 based indexing, left child is at 2*index ,in 0 based indexing it is at 2*index+1
                int right = 2*index + 1; // In 1 based indexing, right child is at 2*index + 1 ,in 0 based indexing it is at 2*index+2
                
                int largest =index; // Because you always need to swap with the largest child to maintain the heap property
               // largest basically keeps the index of the largest element among the current node and its children
                if(left <=size && arr[left] > arr[largest]){
                    largest =left;
                } 
                if(right <=size && arr[right] > arr[largest]){
                    largest=right;
                }
                if(largest!=index){
                    swap(arr[index],arr[largest]);
                    index=largest; // Now we need to check the new index for the heap property
                }else{
                    break; // If the largest is still the index, then we are done
                }
            }
            }
     };

void  heapify(int *arr, int  n ,int index){ // Basically puts the element at its correct position to maintain heap property
    int largest =index;

    // heapify insures that the subtree whose root is a heap

    while(true){
        int left = 2* index  +1 ; // Because 0 based indexing, left child is at 2*index + 1
        int right = 2* index + 2;

        if(left <n && arr[left] > arr[largest]){
            largest =left;
        } 
        if (right < n && arr[right] > arr[largest]){
            largest=right;
        }

        if ( largest !=index){
            swap(arr[index],arr[largest]);
            index=largest; // Now we need to check the new index for the heap property
        }else{
            return ; // If the largest is still the index, then we are done
        }
    }
}
    

//Time complexity of heapify is O(log n) because we are traversing the height of the tree which is log n in a complete binary tree
void heapSort(int *arr , int n){
    // Three steps to sort an array using heap sort:
    // 1. Build a max heap from the array
    //2. Swap the root of the heap with the last element of the heap because root is always the largest so it will be the last element in the sorted array
    //3. Reduce the size of the heap by 1 and heapify the root to maintain the heap property
    // Repeat steps 2 and 3 until the size of the heap is sorted

    // 1. Build a max heap from the array
    // O(n)
    for(int i=n/2 -1;i>=0;i--){ // Start from the last non-leaf node and heapify each node
        heapify(arr,n,i);
    }
    int size =n-1;

    // heapify : O(logn) called n-1 times so O(n log n) in total
    while(size > 0){
        // 2. Swap the root of the heap with the last element of the heap
        swap(arr[0],arr[size]);

        size--; // Reduce the size of the heap by 1
        // 3. Heapify the root to maintain the heap property
        heapify(arr,size,0); // Heapify the root node

    }

}
    
int main(){
   Heap h;
   
   // Time Complexity of insert is O(log n) and delete is O(log n)
   h.insert(50);
   h.insert(55);
   h.insert(53);
   h.insert(52);
   h.insert(54);
   h.print();

   h.deletefromheap();
   h.print();

   // In complete binary tree, the leaf nodes are from n/2 +1 to n where n is the number of nodes in the tree ( for one based indexing)
   // for 0 based indexing, the leaf nodes are from n/2 to n-1
   // So we dont check the leaf nodes for heap property as they always do 

    int arr[]={54,53,55,52,50};
    int n=sizeof(arr)/sizeof(int);

 /*  heapify restores the heap property for a single node at index i.

At each step, you compare the node to its children and possibly swap with the larger child.

After a swap, you repeat the process down the subtree.

How many times can you do this in the worst case?

At most, you travel from the current node down to a leaf.

The height of a binary heap is O(log n) (because it’s a complete binary tree).

*/
    // Time complexity of heapify is O(logn) 
    // But we call heapify for n/2 nodes so the overall time complexity is O(n) of building heap from an array
    /*  Each heapify call is O(log n) in the worst case, but not every node takes that long.

Leaf nodes: 0 swaps

Nodes near bottom: small subtree, tiny work

Root: height = log n, maximum work

So, the actual total cost of building the heap is O(n), not O(n log n)!

Fact: Building a heap in-place from an array is O(n) — you can Google this and see proofs (they use the fact that lower levels have exponentially more nodes but shallower heights).

*/
    for( int i= n/2-1; i>=0;i--){ 
        heapify(arr,n,i);
    }

    cout << "Array after heapify: ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;



    // To implement heap sort,

    int arr2[]={23,45,12,67,89,34,22,11};
    n=sizeof(arr2)/sizeof(int);
    heapSort(arr2,n);

    cout << "Array after heap sort: ";
    for(int i=0;i<n;i++){
        cout << arr2[i] << " ";
    }
    cout << endl;

    priority_queue<int> pq; // By default, it is a max heap
    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(15);
    cout << "Priority Queue (Max Heap): ";
    while(!pq.empty()){
        cout << pq.top() << " "; // Top element is the largest
        pq.pop(); // Remove the top element
    }
    cout << endl;

    priority_queue<int,vector<int>,greater<int> > minHeap; // Min heap
    minHeap.push(10);
    minHeap.push(20);       
    minHeap.push(5);
    minHeap.push(15);
    cout << "Priority Queue (Min Heap): ";
    while(!minHeap.empty()){
        cout << minHeap.top() << " "; // Top element is the smallest
        minHeap.pop(); // Remove the top element
    }
    cout << endl;
    return 0;
}