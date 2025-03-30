#include<iostream>
using namespace std;

class base1{
    int a;
    public:
    base1(int a) : a(a) {
        cout << "Constructor of base1 class" << endl;
        cout << "Value of a is " << a << endl;
    }
};

class base2{
    int b;
    public: 
    base2(int b) : b(b) {
        cout << "Constructor of base2 class" << endl;
        cout << "Value of b is " << b << endl;
    }
};

class derived:public base1,public base2{
    int c;
    public:
    derived(int a ,int b , int c) : base1(a),base2(b),c(c){
        cout << "Constructor of derived class" << endl;
        cout << "Value of c is " << c << endl;
    }
   
};

int main(){
    derived obj(1,2,3);
      return 0;
}