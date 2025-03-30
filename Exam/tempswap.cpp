#include<iostream>
using namespace std;

template<class T>
void swapp(T &a,T &b){
    T temp=a;
    a=b;
    b=temp;
}
int main(){
   
   int a=10,b=20;
    cout<<"Before swapping a="<<a<<" b="<<b<<endl;
    swapp(a,b);
    cout<<"After swapping a="<<a<<" b="<<b<<endl;
    string s1="Hello",s2="World";
    cout<<"Before swapping s1="<<s1<<" s2="<<s2<<endl;
    swapp(s1,s2);
    cout<<"After swapping s1="<<s1<<" s2="<<s2<<endl;
    return 0;
}