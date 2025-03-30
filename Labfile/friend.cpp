#include<iostream>
using namespace std;

class B;

class complex{
    private :
    int a ,b;
    public:
    complex(int x,int y):a(x),b(y){}
    friend void realsum(complex &o1,complex &o2);
    friend class B;
    void display(){
        cout<<a<<" + i"<<b<<endl;
    }
};

void realsum(complex &o1,complex &o2){
        cout << "The sum of real parts is : "<<( o1.a +o2.a )<<endl;
}

class B{
    private :
    int r,c;
    public:
    B(int x,int y):r(x),c(y){}
    void display(){
        cout<<r<<" + i"<<c<<endl;


    }

    void Sum(complex &o1,B &b1){
        int real=o1.a +b1.r;
        int complex =o1.b + b1.c;
        cout << "The new complex is : "<<real <<" + i"<< complex<< endl;
    }
};

int main(){
        complex o1(1,4);
        complex o2(2,5);

        B b1(3,6);

        realsum(o1,o2);

        b1.Sum(o1,b1);
        char name[]="Saoinava ";
        string s="Modak";
        cout <<"name is "<< name<< " + "<< s<<endl;

}
