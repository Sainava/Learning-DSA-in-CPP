#include<iostream>
using namespace std;

class realestate{
    private:
    int price;
    int bathrooms ;
    int bedrooms;
    public:
   void setvalues(int p,int bathrooms,int bedrooms){

         price=p;
         this->bathrooms=bathrooms;
         this->bedrooms=bedrooms;
   }
    void display(){
        cout<<"Price: "<<price<<endl;
        cout<<"Bathrooms: "<<bathrooms<<endl;
        cout<<"Bedrooms: "<<bedrooms<<endl;

    }
};

int main(){
   realestate r1;
   cout << "Enter the price of the property: ";
    int p;
    cin >> p;
    cout << "Enter the number of bathrooms: ";
    int b;
    cin >> b;
    cout << "Enter the number of bedrooms: ";
    int bd;
    cin >> bd;
    
    return 0;
}