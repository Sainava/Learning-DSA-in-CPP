#include<iostream>
using namespace std;

int main(){
    int n;
    cout<< "Enter:" << "\t";
    cin >> n;
    int i=1;
/*
    while (i<=n){
        //space
        int space=n-i;
        while(space>=1){
            cout << " " ;
            space--;
        }
        //num1
        int num=1;
        while(num<=i){
            cout << num;
            num++;
        }
        //num2
        int num2=i-1;
        while(num2){
            cout << num2;;
            num2--;
        }
       

        cout << endl;
        i++;
        }
       */ 
    while(i<=n){
        //num1
        int num=n-i+1;
        int value=1;
        while(num){
            cout << value ;
            value++;
            num--;

        }
        //star
        int star=1;
        while(star<i){
            cout << "*";
            star++;
        }
        //star2
        int star2=1;
        while(star2<i){
            cout << "*";
            star2++;
        }
        //num2
        int num2=n-i+1;
        while(num2){
            cout << num2;
            num2--;
        }

        cout << "\n";
        i++;
      }
}      

