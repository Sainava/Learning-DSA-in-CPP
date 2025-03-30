#include<iostream>
#include<algorithm>
using namespace std;

 int* maxOccChar(string s){
    static int arr[26]={0};

    for (int i=0;i<s.size();i++){
        char ch=s[i];
        int number=0;
        if(ch>='a' && ch<='z'){
            number =ch -'a';
        }
        else if(ch>='A' && ch<='Z'){
            number =ch-'A';
        }
        arr[number]++;
    }

    return arr;

}

int main(){
    string s;
    cout<< "Enter the string : ";
    cin >> s;
    int* arr=maxOccChar(s);
    int maxi=-1;
    int index=-1;
    for(int i=0;i<26;i++){
        if (arr[i]>maxi){
            maxi=arr[i];
            index=i;
        }
        
    }

    cout << "The maximum repeating element in the given string is : " << char('A'+index)<< endl;
}
