#include<iostream>
using namespace std;

class base1 {
    public:
    base1(){
        cout << "Constructor of base1 class" << endl;
    }
};
class base2 {
    public:
    base2(){
        cout << "Constructor of base2 class" << endl;
    }
};

class derived1: public base1 {
    public:
    derived1(){
        cout << "Constructor of derived1 class" << endl;
    }
};

class derived2:virtual public base2{
    public:
    derived2(){
        cout << "Constructor of derived2 class" << endl;
    }
};

class son: public derived1, public derived2 {
    public:
    son(){
        cout << "Constructor of son class" << endl;
    }
};

int main(){
   son obj;
    return 0;
}