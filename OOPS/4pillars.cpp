#include<iostream>
using namespace std;

class Human{
    private :
    int age ;

    public:
    int weight;
    int height;

    void sleep(){
        cout << "Sleeping" << endl;
    }

    int  getage(){
        return age ;
    }

};

class male:public Human{
            public : 
            char skin_tone;

            void walking (){
                cout << "Walking" << endl;
            }

    
};

int main(){
        male m1;
        cout << sizeof(m1) << endl;
        cout << m1.getage() << endl;
}