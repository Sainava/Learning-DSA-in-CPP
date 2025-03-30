#include<iostream>
using namespace std;

int main(){
    
    // int n=1;

    // switch(n){

    //     case 1: cout << "int 1" << endl;
    //                 break;

    //     case '1': cout << "char 1" << endl;
    //                 break;

    //     default: cout << "default" << endl;
    // }


    int n;
    cout << "Enter the amount:" << " ";
    cin >> n;
    cout << endl;
    int choice;
    cout << "Enter choice(100/50/20/10/1)" << " " ;
    cin >> choice;

    int R100= (n/100);
    int R50 = (n-(R100*100))/50;
    int R20= (n-(R100*100) -( R50*50))/20;
    //int R10= (n-(R100*100) -( R50*50) - (R20*20))/10;
    int R1= (n-(R100*100) -( R50*50) - (R20*20)) ;

    switch(choice){

        case 100: 
        cout << "No of 100 rupee notes required : " << " " << R100<< endl;
            break;

        case 50: 
            cout << "No of 50 rupee notes required : " << " " << R50 << endl;
            break;

        case 20  :
            cout << "NO of 20 rupee notes required : " << " " << R20<< endl;
            break;

        // case 10: 
        //     cout << "NO of 10 rupee notes required : " << " " << R10 << endl; 
        //     break;

        case 1 :
            cout << "NO of 1rupee notes required : " << " " << R1 << endl; 
            break;

        default : cout << "Please Enter valid choice " << endl;
    }

}