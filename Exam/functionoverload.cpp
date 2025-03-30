#include<iostream>
using namespace std;

double area(double r){
    return 3.14*r*r;
}
int area(int l,int b){
    return  (l*b);
}

double area(double b,double h){
    return 0.5*b*h;
}

int area(int a){
    return a*a;
}


int main(){
   cout << "The area of a circle with radius 5 is " << area(5.0) << endl;
   double b=5,h=10;
   cout << b<< h<<endl;
    cout << "The area of a rectangle with length 5 and breadth 10 is " << area(5,10) << endl;
    cout << "The area of a triangle with base 5 and height 10 is " << area(b,h) << endl;
    cout << "The area of a square with side 5 is " << area(5) << endl;
    return 0;
}