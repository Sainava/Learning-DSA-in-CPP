#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number:" << endl;
    cin>> n;
    int i=1;
    /*while (i<=n){
        cout << i << " " ;
        i+=1;

    }*/
   int sum=0;
   while(i<=n){
    sum=sum + i;
    i=i+2;
   }
   cout << "The sum is : " << sum << endl;
   bool x=true;
   cout << " Bool is : " << x;

}