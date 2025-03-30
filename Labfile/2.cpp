#include <iostream>
using namespace std;

int fibonacci(int n){
    if (n==1||n==0){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);

}

void printFib(int n){
    for(int i=0;i<n;i++){
        cout << fibonacci(i) << " ";
    }
    cout << endl;
}


int main(){
     int n;
    cout << "Enter the no of terms:" << " ";
    cin>>n;
    printFib(n);
}