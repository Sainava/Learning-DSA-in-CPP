#include<iostream>
using namespace std;

int main(){
    int n;
    cout<< "Enter:" << "\t";
    cin >> n;
    int row=1;
    /*
    while (row<=n){
        //space 
        int space=n-row;
        while(space>=1){
            cout << " " ;
            space--;
        }
        // star
        int star=1;
        while(star<=row){
            cout << "*" ;
            star++;
        }
        cout << endl;
        row++;
    }
    */
   /*
   while(row<=n){
    int col=n-row+1;
    while(col>=1){
        cout<< "*" ;
        col--;
    }
    cout << "\n" ;
    row++;
   }
    */
/*
    while(row<=n){
    int col=n-row+1;
    //space
    int space=1;
    while (space<row){
        cout << " " ;
        space++;
    }
    //star
    while(col>=1){
        cout<< "*" ;
        col--;
    }
    cout << "\n" ;
    row++;
   }
*/
/*
 while(row<=n){
    int col=n-row+1;
    //space
    int space=1;
    while (space<row){
        cout << " " ;
        space++;
    }
    //star
    while(col>=1){
        cout<< row ;
        col--;
    }
    cout << "\n" ;
    row++;
   }
*/
/*
while(row<=n){
    //space
    int space=n-row;
    while (space>=1){
        cout << " " ;
        space--;
    }
    //number
    int num=1;
    while(num<=row){
        cout << row ;
        num++;

    }
    cout<< "\n";
    row++;
}
*/
/*
while(row<=n){
    int col=n-row+1;
    //space
    int space=1;
    while (space<row){
        cout << " " ;
        space++;
    }
    //star
    int value=row;
    while(col>=1){
        cout<< value ;
        col--;
        value++;
    }
    cout << "\n" ;
    row++;
   }
   */
  int value =1;
  while(row<=n){
    //space
    int space=n-row;
    while(space>=1){
        cout << " ";
        space--;
    }
    // num
    int col=1;
    while(col<=row){
        cout << value ;
        value++;
        col++;
    }
    cout << "\n";
    row ++;

  }

}