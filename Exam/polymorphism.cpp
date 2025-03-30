#include<iostream>
using namespace std;

class base{
    int value1;
    public:
    base(int a): value1(a){}

    virtual void display()
    {
        cout << "Value1 is " << value1 << endl;
    }
};

class derived: public base{
    int value2;
    public:
    derived(int a,int b): base(a),value2(b){}

    void yeho(){
        cout << "Yeho" << endl;
    }

    void display() {
        cout << "Value2 is " << value2 << endl;
    }
};

int main(){
    derived obj(1,2);
    base * bptr=&obj;
    
    bptr->display();
    derived *d=dynamic_cast<derived*>(bptr);
    d->yeho();
    bptr->display();

    return 0;
}