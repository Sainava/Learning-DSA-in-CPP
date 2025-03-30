#include<iostream>
using namespace std;

const int MAX=100;

struct Mystruct{
    int a;
    double b;
    char c;
  
    char name [100];
};


int main(){

    int MAX=20;
        //cout << "THe size of structure is : "<< sizeof(Mystruct) << endl;
    cout << "Local MAX : " << MAX << endl;
    cout << "Global MAX : " << ::MAX << endl;

}