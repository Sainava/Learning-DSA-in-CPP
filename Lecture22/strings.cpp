#include<iostream>
#include<algorithm>
#include<array> 

using namespace std;

char toLowerCase(char ch){
    if (ch>='a' && ch<='z'){
        return ch;
    }
    else{
        char temp = ch -'A' +'a';
        /* For Lower to upper
            ch-'a' + 'A'
        */
        return temp;
    }
}

int length(char arr[]){
    int count =0;
    int i=0;
    while(arr[i]!='\0'){
        count ++;
        i++;
    }
    return count;
//    cout  << "You have " <<count << " characters in your string"<< endl;
}

bool palindrome(char arr[]){
     int n=length(arr);
     int s=0;
     int e=n-1;
     while(s<=e){
        if (toLowerCase(arr[s++])!= toLowerCase(arr[e--])){
           return 0;
        }
     }
     return 1;
}

void reverse(char arr[]){
        int n=length(arr);
        for(int i =0;i<n/2;i++){
            swap(arr[i],arr[n-1-i]);
        }

}

int main(){
    char name[20];
    
    cout << "Enter your Name : " ;
    cin >> name;
    //name[2]='\0'; Ouput stops at 2 idex so only 0 ad 1 index are printed as Cout stops printing string when it encounters the fist null character ‘\0’
   
    // cout << "Your name is : " << name << endl;
    // reverse(name);
    // cout << " After reversal:  "<< name <<endl; 

    bool ans=palindrome (name);
     if (ans){
        cout << "IS a Palindrome" << endl;
     }
    else{
         cout << "Not a Palindrome" << endl;
    }

}