#include<iostream>
using namespace std;

class employee{
    string name ;
    int ID ;
    public:
    void setname(string name){
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
};

int main(){
   //employee FB[4];
    employee *FB=new employee[4];
   for (int i=0;i<4;i++){
         string name;
         int ID;
         cout << "Enter the name of the employee : ";
         cin.ignore();
        getline(cin,name);
        cout << "Enter the ID of the employee : ";
        cin >> ID;
        FB[i].setname(name);
        FB[i].setID(ID);

   }

   for (int i=0;i<4;i++){
       FB[i].get();
   }
    return 0;
}