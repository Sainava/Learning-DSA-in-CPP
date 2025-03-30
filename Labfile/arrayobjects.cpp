#include<iostream>
using namespace std;

class employee{
    private :
    string name;
    int age ;

    public:
    // employee(string s ,int a){
    //     cout << "Constructor called" << endl;
      
    // }

    void  setname(string s){
            name = s;
    }
    void setage(int a){
        age = a;
    }

    string getname(){
        return name;
    }

    int getage(){
        return age;
    }

};



int main(){
  int n;
  cout << "Enter the number of employees" << " ";
    cin>>n;
    employee  Staff[n] ;

    for (int i=0;i<n;i++){
        string s;
        int age;
        cout << "Enter the name and age of the employee " << i+1<<" ";
        cin>>s>> age ;
        // cout << "Enter the age of the employee" << " ";
        // cin>>a;
        Staff[i].setname(s);
        Staff[i].setage(age );
    }cout<<endl;  

    for(int i=0;i<n;i++){
        cout << "The name of the employee "<<i+1<< " is : " << Staff[i].getname() << " and the age is : " << Staff[i].getage() << endl;
    }

}

