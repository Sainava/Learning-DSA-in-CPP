#include<iostream>
using namespace std;

class complex;
class calculator{
    public:
    int add(int a,int b){
        return (a+b);
    }
    int realcomplex(const complex ,const complex );
};

class complex{
    private: 
    int a;
    int b;
    public :
    
    complex(int x,int y=10){
        this ->a=x;
        this->b=y;
    }
    void setdata (int x,int y){
        a=x;
        b=y;
    };
    void display() {
        cout << "The value of a is : " << a << " and b is : " << b << endl;
    }
    friend int calculator::realcomplex(const complex ,const complex );

};

int calculator::realcomplex(const complex c1,const complex c2){
        return (c1.a+c2.a);
    }



int main(){
   calculator calc;
    complex c1(5, 7), c2(8, 12);

    cout << "Sum of real parts: " << calc.realcomplex(c1, c2) << endl;
    return 0;
}