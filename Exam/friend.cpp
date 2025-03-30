#include<iostream>
using namespace std;

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
    friend complex sumcomplex(const complex &c1,const complex &c2);

};

complex sumcomplex(const complex &c1,const complex &c2){
    complex temp(3);
    temp.a=c1.a+c2.a;
    temp.b=c1.b+c2.b;
    return temp;

}

int main(){
   complex c1(8,34);
    complex c2(54,78);
    complex c3 = sumcomplex(c1,c2);

   c1.display();
    c2.display();
    c3.display();
    return 0;
}