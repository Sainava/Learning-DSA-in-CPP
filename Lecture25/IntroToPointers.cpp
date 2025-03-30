#include <iostream>
using namespace std;

int main() {
    // Your code here
    // int *p; Never Do this;
    int *p1=NULL;
    int *p2=nullptr;
    int *p3=0;//SEGMENTATION FAULT - No Error 

    //int *p4=&5; ERROR AS 5 DOES NOT HAVE AN ADDRESS AS IT IS TEMPORARY AND HAS UNACCESSIBLE MEMORY

    int a=10;
    int *p=&a;
    cout << "The address of a is : " << &a << endl;
    cout << "The address of a is : " << p<< endl;
    std::cout << "The value at the address pointed to is : "<< *p << std::endl;
    cout << "The size of pointers is always : " << sizeof(p) << endl;

    int i=3;
    char c='a';
    float f=3.14;
    double d=3.1415;
    int *ip=&i;
    char *cp=&c;
    float *fp=&f;
    double *dp=&d;

    cout << "The size of int pointer is : " << sizeof(ip) << endl;
    cout << "The size of char pointer is : " << sizeof(cp) << endl;
    cout << "The size of float pointer is : " << sizeof(fp) << endl; 
    cout << "The size of double pointer is : " << sizeof(dp) << endl;


    int x=5;
    int *ptr=&x;
    int y=x;
    int z=*ptr;
    y++;
    z++;
    cout << "The value of x if y is incremented is : " << x << endl;
    cout << "The value of x if z is incremented is : " << *ptr << endl;
    //*ptr++;// does not work as postfix ++ has slightly greater precedence than * so it increments the address and not the value;
    //(*ptr)++ This works
    ++*ptr;//works as prefix ++ has same  precedence than * so it increments the value and not the address;   
    cout << "In C/C++, precedence of Prefix ++ (or Prefix –) has same priority than dereference (*) operator, and precedence of Postfix ++ (or Postfix –) is higher than both Prefix ++ and *.  If p is a pointer then *p++ is equivalent to *(p++) and ++*p is equivalent to ++(*p) (both Prefix ++ and * are right associative)." << endl;
    cout << "The value of x if *ptr is incremented is : " << x << endl;

    int *q=ptr;
    (*q)++;
    cout << "The value of x if *q is incremented is : " << x << endl;
    cout << "The above changes as q is accessing the same value of x : "<<endl;
    
    int abc=10;
    int *t=&abc;
    *t=*t +1;
    cout << "The address of abc is : " << t << endl; //0x16dda3384
    cout << "*t=*t +1 increases the value it is pointing to by 1 : " << abc << endl;//
    t=t+1;
    cout << "t=t+1 increases the address by size of data type(here int so by 4 bytes so the last place of address increments by  ) : " << t << endl;//0x16dda3388
    t=t+1;
    cout << "t=t+1 increases the address again by 4 bytes  : " << t << endl;//0x16dda338c
     t=t+1;
    cout << "t=t+1 increases the address again by 4 bytes  : " << t << endl;//0x16dda3390
     t=t+1;
    cout << "t=t+1 increases the address again by 4 bytes  : " << t << endl;//0x16dda3394

    return 0;
}