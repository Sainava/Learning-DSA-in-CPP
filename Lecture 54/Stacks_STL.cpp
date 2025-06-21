#include<iostream>
#include<stack>
using namespace std;

int main(){
   
    stack <int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.pop();
    st.push(40);
    st.push(50);

    cout << "Size of stack : " << st.size() << endl;
    cout << "Top element of stack : " << st.top() << endl;

    cout << "Printing the stack : ";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    st.push(60);
    st.push(70);
    //cout << " Does pop operation return the top element? " << st.pop() << endl; --> NO

    return 0;
}