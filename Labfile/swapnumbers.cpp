#include<iostream>
using namespace
std;

class y;
class x{
    int val1;
    public:
    int getdata(){
        return val1;
    }
    void setdata(int a){
        val1=a;
    }
    friend void swap(x &x1,y &y1);
};

class y{
    int val2;
    public:
    int getdata(){
        return val2;
    }
    void setdata(int a){
        val2=a;
    }
    friend void swap(x &x1,y &y1);
};

void swap(x &x1,y &y1){
    int temp=x1.val1;
    x1.val1=y1.val2;
    y1.val2=temp;
}

int main(){
    x x1;
    y y1;
    x1.setdata(10);
    y1.setdata(20);
    cout<<"Before swapping"<<endl;
    cout<<"x1 = "<<x1.getdata()<<endl;
    cout<<"y1 = "<<y1.getdata()<<endl;
    swap(x1,y1);
    cout<<"After swapping"<<endl;
    cout<<"x1 = "<<x1.getdata()<<endl;
    cout<<"y1 = "<<y1.getdata()<<endl;
}