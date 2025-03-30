#include<iostream>
using namespace std;

class Array{
    private:
    int *arr;
    int size;
    public:
    Array(int s): size(s){
        arr=new int[size];
        for(int i=0;i<size;i++){
            arr[i]=0;
        }

    }

    void operator+(){
        for(int i=0;i<size;i++){
            arr[i]++;
        }
    }

    void display(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    ~Array(){
        delete [] arr;
    }
};

int main (){
    Array a(5);
    a.display();
    +a;
    a.display();
    cerr<<"Error"<<endl;
}
