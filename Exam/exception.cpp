#include<iostream>
#include<exception>

#include<string>
using namespace std;

class Insufficient_fund:public runtime_error{
    public:
        Insufficient_fund(const string &message): runtime_error(message){}
    
    // string what(){
    //     return "Insufficient fund";
    // }
};

class employee{
    private:
    string name;
    int balance ;
    int account_number;
    public:
    employee(string name,int balance ,int account_number){
        this->name=name;
        this->balance=balance;
        this->account_number=account_number;

    }

    void withdraw(int amount){
        if(amount<0){
            throw runtime_error("Amount cannot be negative");
        }
        if (amount >balance){
            throw Insufficient_fund("Insufficient balance");
        }
        balance-=amount ;
        cout << amount << "rs withdrawn successfully"<<endl;
    }

    void deposit(int amount){
        if(amount<0){
            throw ("Amount cannot be negative");
        }
        balance+=amount;
        cout << amount << "rs deposited successfully"<<endl;
    }
};



int main(){
   employee emp("Sainava",5000,123456);

   try{
    emp.deposit(100);
    emp.withdraw(20000);
    emp.withdraw(-100);
   }
   catch(const Insufficient_fund &e){
       cout << "Insufficient_fund "<<e.what()<<endl;
   }
   catch(const char *e){
       cout << "Error "<<e<<endl;
   }
    catch(const runtime_error &e){
         cout << "runtime _Error "<<e.what()<<endl;
    }

    // try{
    //     int *arr;
    //     arr=new int[200000000000000000];
    //     delete [] arr;
    // }
    // catch(const exception &e){
    //     cout << "Exception "<<e.what()<<endl;
    // }
    return 0;
}