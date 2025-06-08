#include<iostream>
using namespace std;

int main(){

    int arr[10]={10,2,5,7,21};
    // for(int i=0;i<10;i++){
    //     cout << arr[i] << " ";
    // }
    cout << "The address of first memory block is : " << arr << endl;
    cout << "The address of afirst memory block  is : " << &arr[0] << endl;

    cout << "3 : "<< *arr<<endl;
    cout << "4: "<< *(arr+1)<<endl;
    cout << "5 : "<< *arr+1<<endl;
    cout << "6 : "<< *(arr)+1<<endl;

    cout << "7 : "<< arr[2]<<endl;
    cout << "8 : "<< *(arr+2)<<endl;
    cout << "9 : "<< 2[arr]<<endl;
    cout << "10 : "<< *(2+arr)<<endl;

    cout << "11 : "<< &*arr<<endl;

    cout << "12 : "<< &arr<<endl;

    cout << "13 : "<< &arr+1<<endl;
    cout << "14 : "<< arr+1<<endl;

    int *p=arr;
    cout << "15 : "<< p<<endl;
    cout << "16 : "<< *p<<endl;

    cout << "Just now : "<< &arr[0] << endl;
    cout << "Just now : "<< &arr << endl;
    cout << "Just now : "<< arr << endl;

    /*
    cout << "17 : "<< &(p+1)<<endl;
    Now, when you do p + 1, you're performing pointer arithmetic. This expression:

Evaluates to a new pointer pointing to the memory location immediately after p (in this case, arr[1]).
p + 1 itself is a temporary pointer, not an lvalue (it doesn't have a specific address in memory).
Why &(p + 1) Fails
The & operator requires an lvalue (an expression that refers to a memory location). However, p + 1 is a temporary pointer created by pointer arithmetic, so it doesn't have a stable address in memory. C++ therefore disallows taking the address of this temporary result, and you get an error.*/
    

    //arr++;//Not allowed
    cout<< "17 : arr++ and arr=arr+1 is not allowed as arr  is not like a normal pointer" << p<<endl;
    cout << "18 :  p++ is allowed : "<< p++<<endl; 
    cout << "19 : "<< p<<endl;
    cout << "20 : "<< *(p+1)<<endl;
    p=p+1;
    cout << "21 : "<< p<<endl;
    cout << "22 : "<< *&p<<endl;

    int *a=&arr[0]; 
    int *b=arr;
    int (*c)[10]= &arr; // Pointer to the entire array

    cout << a+1 << endl; // Incrementing pointer to the first element ---> Moves 4 bytes 
    cout << b+1 << endl; // Incrementing pointer to the first element ---> Moves 4 bytes 
    cout << c+1 << endl; // Incrementing pointer to the entire array ---> Moves 40 bytes (10 * sizeof(int))

    int array[10];
    cout << "23 : array=array+1 is not allowed as array is not like a normal pointer" << arr<<endl;
    cout << "24: arr " << arr<<endl;
    cout << "25: array + 1 : " << arr +1 <<endl;
    int *p1=arr;
    cout << "26: "<< p1 + 1 <<endl;


    
}