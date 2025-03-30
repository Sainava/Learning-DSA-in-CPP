#include<iostream>
using namespace std;


class student {
    protected:
    int roll_no;
    string name;
    int age;
    public:

    student(){
        cout <<"Constructor called for student "<<endl;
    }
    void setstudent(int roll_no,string name,int age){
        this->roll_no=roll_no;
        this->name=name;
        this->age=age;
    }

    void getstudent(){
        cout << "The roll no of the student is : " << roll_no << endl;
        cout << "The name of the student is : " << name << endl;
        cout << "The age of the student is : " << age << endl;
    }
};

class exam : public student{
    protected:
    int marks[6];
    public:
    exam(){
        cout <<"Constructor called for exam "<<endl;
    }
    void setmarks(){
        int sum=0;
        cout << "Enter the marks of the student in 6 subjects : " << endl;
        for(int i=0;i<6;i++){
            cout << "Marks for the subject"<< i+1 << " : ";
            cin >> marks[i];
            cout<<endl;
        }
         }
    void displaymarks(){
        cout <<"the marks in 6 subjects: "<<endl;
        for (int i=0;i<6;i++){
                cout <<"Subject : " << i+1 << marks[i]<<endl;
        }
    }
};
class result: public exam{
    protected:
    int total_marks;
    public:
        int totalmarks(){
            total_marks=0;
            for(int i=0;i<6;i++){
                total_marks+=marks[i];
            }
        return total_marks;
        }

        void displayresult(){
            getstudent();
            displaymarks();
            cout << "The total marks of the student is : " << totalmarks() << endl;
        }
};

int main(){
   result student1;
   student1.setstudent(1,"Sainava",20);
   student1.setmarks();
   student1.displayresult();
    return 0;
}