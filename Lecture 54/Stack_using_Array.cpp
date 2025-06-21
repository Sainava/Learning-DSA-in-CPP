#include <iostream>
using namespace std;

class Stack
{
public:
    // properties
    int *arr;
    int top;
    int size;

    // behaviour
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow : " <<" " ;
            return -1;
        }
        int data = arr[top];
        top--;
        return data;
    }

    bool empty()
    {
        return top == -1;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty: " << " ";
            return -1;
        }
        return arr[top];
    }

    void print(){
        if(top==-1){
            cout << "Stack is empty" << endl;
            return;
        }
        int i = this->top;
        while (i != -1)
        {
            cout << arr[i] << " ";
            i--;
        }
        cout << endl;
    }
};

int main()
{
    Stack st(5);
    cout << "Top element: " << st.peek() << endl; 
    cout << "Popped element: " << st.pop() << endl; 
    st.push(10);
    st.push(20);
    st.push(30);
    st.print();
    cout << "Top element: " << st.peek() << endl;
    cout << "Popped element: " << st.pop() << endl;
    cout << "Top element after pop: " << st.peek() << endl;
    st.push(30);
    st.push(40);
    st.push(50); 
    st.push(60); 
    st.print();
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;
    return 0;
}