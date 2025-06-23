#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
   

    queue<int> q;
    int n;
    cout << "Enter the number of elements in the queue: ";
    cin >> n;
    cout << "Enter the elements of the queue: ";
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    q.emplace(10); // Add 10 to the end of the queue

    q.empty() ? cout << "Queue is empty" : cout << "Queue is not empty" << endl;
    cout << "Size of the queue: " << q.size() << endl;

    int sz= q.size();
    cout << "Elements in the queue: ";
    for(int i=0;i<sz;i++){
        cout << q.front() << " ";
        q.pop();// Remove the front element
    }
    cout << endl;


    // Dequeue operations
    deque<int> dq;
    dq.push_back(10);
    dq.push_front(1);
    dq.push_back(20);
    dq.push_front(2);
    dq.emplace_back(30); // Add 30 to the end of the deque
    dq.emplace_front(0); // Add 0 to the front of the deque

    cout << "Elements in the deque: ";
    for(int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";
    }cout << endl;

    dq.pop_back();
    dq.pop_front();
    cout << "Elements after popping: ";
    for(int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";
    }cout << endl;

}