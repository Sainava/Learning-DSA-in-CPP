#include<iostream>
using namespace std;

class base1{
        public :
        void greet(){
            cout << "How are you?" << endl;
        }
};

class base2{
        public :
        void greet(){
            cout << "Kaise ho?" << endl;
        }
};

class derived: public base1,public base2{
    public:
    void greet(){
        base1::greet();
        base2::greet();
        cout <<"Hey YO YO YO "<<endl;
    }
};

int main(){
   
   derived obj;
   obj.greet(); // This will give an error
    return 0;
}