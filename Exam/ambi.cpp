#include<iostream>
using namespace std;

class student{
    protected :
    int roll_no;
    public :
    student(){
        cout << "Constructor of student class" << endl;}
    void set_roll_no(int a){
        roll_no=a;
    }
    void get_roll_no(){
        cout<<"Roll no is "<<roll_no<<endl;
    }
};

class test:virtual public student{
    protected:
     float maths;
     float physics;
    public:
    test(){
        cout << "Constructor of test class" << endl;}
    void set_marks(float m1,float m2){
        maths=m1;
        physics=m2;
    }
    void get_marks(){
        cout<<"Marks in maths are "<<maths<<endl;
        cout<<"Marks in physics are "<<physics<<endl;
    }

};

class sports:virtual public student{
    protected:
    float score;
    public:
    sports(){
        cout << "Constructor of sports class" << endl;}
    void set_score(float sc){
        score=sc;
    }
    void get_score(){
        cout<<"Score is "<<score<<endl;
    }
};

class result:public test,public sports{
    protected:
    float total;
    public:
    result(){
        cout << "Constructor of result class" << endl;}
    void totalmarks(){
        total=maths+physics+score;
    }
    void display(){
        cout<<"Roll no is : "<<roll_no<<endl;
        get_marks();
        get_score();
        cout<<"Total marks is "<<total<<endl;

    }

};

int main(){
   result obj;
//    obj.set_roll_no(101);
//     obj.set_marks(90.0,85.0);
//     obj.set_score(90.0);
//     obj.totalmarks();
//     obj.display();

    return 0;
}