#include<iostream>
using namespace std;

int main(){
    int a;
    cout << " Enter the choice \n 1.Celius to fahrenheit \n 2.Fahrenheit to celsius" << "\n" ;
   
    cin >> a;
    if (a==1){
        float temp;
         cout << " Enter the temperature" << " " ;
         cin >> temp;
         float f=((9.0/5)*temp + 32);
         cout << "The fahrenheit equivalent is " << f << endl;
    }

    else if (a==2){
         float t;
         cout << " Enter the temperature" << " " ;
         cin >> t;
         float c=((t-32)*(5.0/9));
        cout << "The celsius equivalent is " << c<< endl;

    }
    else {
        cout << "Please enter valid choice " << endl;
    }

}


