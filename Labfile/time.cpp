#include<iostream>
using namespace std;

class Time{
    private :
    int hours,mins;

    public:

    Time():hours(0),mins(0){}
     
    Time (int h,int m): hours(h),mins(m){}

    void  setTime(int h,int m){
            hours = h;
            mins = m;
           
    }

    Time Sum(const Time &t1,const Time &t2){
           Time t;
    t.hours=t1.hours+t2.hours;
    t.mins=t1.mins+t2.mins;
    if(t.mins>=60){
        t.hours++;
        t.mins-=60;
    }
    return t;
    }
    
    int  gethours(){
        return hours;
    }

    int getmins(){
        return mins;
    }

};



int main(){
    Time t1(2,37);
    Time t2(3,45);

    Time t3;
    t3=t3.Sum(t1,t2);
    cout<<"Sum of Time is : "<<t3.gethours()<<" hours and "<<t3.getmins()<<" minutes"<<endl;

}