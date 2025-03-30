#include<iostream>
using namespace std;

class employee{
    private :
    static int count ;
    public:
    employee(){
        cout << "Constructor called" << endl;
        count++;
    }
    static int getcount(){
        return count;
    }

};

int employee::count =69;

int main(){
   // employee::count=100;
    //cout << employee::count << endl;
    employee e1,e2,e3;
    cout << employee::getcount()<< endl;;
}

