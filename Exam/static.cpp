#include<iostream>
using namespace std;

class employee{
    mutable string name ;
    int ID ;
    static int count;
    public:

    employee(){
        count++;
        cout<<"No of objects created: "<<count<<endl;
    }
    
    void setname(string name) const{
        this->name=name;
    }
    void setID(int ID){
        this->ID=ID;
    }
    void  get(){
        cout <<endl;
        cout << "[ Name : " << name << " "<< "ID "<< ID << " ]"<<endl;
        cout <<endl;
    }
    static int getcount(){
        return count;
    }
};

int employee::count=10000000;
int main(){
   //cout << employee::count << endl;
//    employee e1;
//    e1.getcount();

    cout << "The value of count is : " << employee::getcount() << endl;
    employee e1,e2,e3,e4;
    cout << "The value of count is : " << employee::getcount() << endl;

    const employee e5;
    e5.setname("Sainava");

   employee *e6=new employee();
   delete e6;

    return 0;
}