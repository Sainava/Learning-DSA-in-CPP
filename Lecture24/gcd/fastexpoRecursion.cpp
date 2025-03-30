#include<iostream>
using namespace std;


int fastExpo(int a,int b){
    if(b==0){
        return 1;
    }
    else if(b==1){
        return a;
    }

    else {
        int result =fastExpo(a,b/2);
        if (!(b&1)){
            return result*result;
        }
        else{
            return result*result*a;
        }
    }
}

int main() {

    int a,b;
    cout << "Enter the Values of a and b" << endl;
    cin >> a >> b;

    cout << "Answer is: " << fastExpo(a,b) << endl;

    return 0;
}
