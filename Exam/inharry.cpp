#include<iostream>
using namespace std;

class base{
    private:
        int data1;
    public :
        int data2;
        void setdata(){
            data1=10;
            data2=20;
        }
        int getdata1(){
            return data1;
        }
        int getdata2(){
            return data2;
        }
};

class derived: public base{
    public :
        int data3;

        void setdata3(){
            data3=base::getdata1()*data2;
        }
        void display(){
            cout<<"Data1: "<<base::getdata1()<<endl;
            cout<<"Data2: "<<data2<<endl;
            cout<<"Data3: "<<data3<<endl;
        }
};

int main(){
   derived obj;
    obj.setdata();
    obj.setdata3();
    obj.display();
    return 0;
}