#include<iostream>
using namespace std;


class Base{
    private : 
    int a=10;
    public:
    int b=20;
    // void setdata(int a1,int b1){
    //     a=a1;
    //     b=b1;
    // }
    // void getdata(){
    //     cout<<"The value of a is : "<<a<<endl;
    //     cout<<"The value of b is : "<<b<<endl;
    // }
    void display(){
        cout <<"This is the base class function"<<endl;
    }
    void showA(){
        cout<<"The value of a is : "<<a<<endl;
    }

};

class pubicderived : public Base{
    public:
    void show(){
        cout<<"This is the public derived class function"<<endl;
    }
    
};

class privatederived : private Base{
    public:
    void reveal(){
        cout<<"This is the private derived class function"<<endl;
    }
void showb(){
    cout<<"The value of b is : "<<b<<endl;
    cout << "The value of a is not accessible"<<endl;
}
};

int main(){
    pubicderived d1;
    d1.display();
    cout << d1.b << endl;
    d1.showA();

    privatederived d2;
    d2.reveal();
    d2.showb();
    string s="Modak";
}