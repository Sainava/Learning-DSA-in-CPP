#include<iostream>
#include<queue>
using namespace std;

class MyStack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x); // Push to empty q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2); // Now q1 has the new order
    }

    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};


int main(){
   
    return 0;
}

