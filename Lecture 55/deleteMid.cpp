#include<iostream>
using namespace std;

void solve(stack<int>&inputStack, int N,int count){
   if(count==N/2){
      inputStack.pop();
      return;
   }

   int num=inputStack.top();
   inputStack.pop();

   solve(inputStack, N,count+1);

   inputStack.push(num);
   return;
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   int count =0;
   solve(inputStack,N,count);
   
   
}



int main() {
    stack<int> s;
    // s.push(5);
    // s.push(6);
    // s.push(7);
    // s.push(8); // Top → 8

    s.push(83);
    s.push(74);
    s.push(67);
    s.push(49);
    s.push(94);
    s.push(8);
    s.push(11);
    s.push(1); 

    deleteMiddle(s, s.size()-1); 

    // Print resulting stack from bottom to top
    vector<int> result;
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    reverse(result.begin(), result.end());

    for (int val : result)
        cout << val << " ";
    return 0;
}
