#include<iostream>
#include<string>
#include<cstring>
using namespace std;

string change(string s){
    for (int i=0;i<s.length();i++){
       if(s[i]==' '){
        s.replace(i,1,"%20");
       }
    }
    return s;

}

string remove(string s){
    for (int i=0;i<s.length();i++){
         if(s[i]==' '){
          s.replace(i,1,"");
         }
    }
    return s;
}

int main(){
   
    // char s[100]="Sainava";
    // char cat[100]="Modak";
    // string s1("Sainava");
    // strcat(cat,s);
    // cout << cat << endl;
    // string  m=s1 + "Modak";
    // cout << s1 << endl;
    // cout << m << endl;
    
    // string p="I" + string("ama") + "Great mfs";
    // char * s="Sainava";
    // s++;
    // cout << s << endl; 
    // char cs[]= "Sainava";
    // cs[0]='p';
    // cout << cs << endl;
    //string s;
    // char *cs=new ;
    // cout<< "Enter a string: ";

    // cin >> s;
    // cout << "Enter a string: ";
    // cin >> cs;
    // cout << s << endl;
    // cout << cs << endl;

    // cs[0]='p';
    // cout << cs << endl;

    // string s;
    // char cs[100];
    // cout << "Enter a string: ";
    // getline(cin,s);
    // cout << "Enter a string: ";
    // cin.getline(cs,5);
    // cout<< "The strinf object is :" << s << endl;
    // cout << "The character array is : " << cs << endl;
    // string s="Sainava";
    // string m="SAINAVA";
    // cout << (s<m) << endl;

    // bool b= 0.0001;
    // if (b){
    //     cout << "True" << endl;
    // }
    // else{
    //     cout << "False" << endl;
    // }

    // string s="Sainava";
    // int n=s.find("crazy");
    // cout << n << endl;
    // cout << string::npos << endl;
    // cout << s.length() << endl;
    // cout << s.substr() << endl;
    // string n="12345";
    //  n.replace(1,3,"s");
    // cout << n << endl;
    // s.insert(3,"Modak");
    // cout << s << endl;
    // s.erase();
    // cout << s.empty()<< endl;
    //  string s="SainavaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaC";
    //  cout << s.length() << endl;//OUTPUT IS 110
    // int loc = s.find(67,'A');
    // cout << loc << endl;//OUTPUT IS 109

    // s.clear();
    // cout << s << endl;
    // int loc=s.find('aessn');
    // cout << loc << endl;
// string x="FROM:ayoussef@gmat.edu";
// int colonPos=x.find(':'); 
// string prefix=x.substr(0,colonPos); //=FROM
// string suffix = x. substr(colonPos+1);
// cout<<prefix << " -This message is from "<<suffix<<endl;

// char s[100]="Sainava\0Modak";
// cout << s << endl;
// for(int i=0;i<21;i++){
//     cout << s[i] << "";
// }
// // int a[100]={1,2,3,45};
// // for(int i=0;i<100;i++){
// //     cout << a[i] << " ";
// // }
// string s1="Sianava \0 Modak ";
// s1.push_back('\0');
// s1.push_back('M');
// cout << s1<< endl;

//string s="Sainava MOdak Is the GOAT";
// int i=0;
// int count=0;
// while(s[i]!='\0'){
//     cout << s[i];
//     count++;
//     i++;
// }cout <<endl;
// s=change(s);
// cout<<s<<endl;
// string s="Sainava Modak12345678913";
// cout <<"THe length fo the string is :"  << s.length() << endl;
// cout << "The capacity of the string is : " << s.capacity() << endl;
// cout <<"The max size of the string is : " << s.max_size() << endl;
// cout <<"The 2nd element is "<< s.at(1)<< endl;
// cout <<"The last element is :"<<s.back()<< endl;
// s.append("Sainava");
// cout << s << endl;
// cout << "The comparison :"<<(s.compare("SAinava"))<<endl;
// cout <<"The other comaprison " << (s==("Sainava")) << endl;

// int n=12;
// string temp=to_string(n);
// cout << (temp.substr(1,34))<< endl;

// char arr[21];
// cout <<"Enter a line :"<<" ";
// cin.getline(arr,21,'\n');
// cout << "The string is : " << arr << endl;

string *s=new string[5];
s[0]="Sainava";
int *n=new int[5];
n[0]=5;

// string sl;
// for (int i=0;i<5;i++){
//     cout << "Enter a string : ";
//     getline(cin,s[i]);
// }
// //cout << "the size of the array is : " << sizeof(sl) << endl;
for (int i=0;i<5;i++){
    cout << s[i] << " ";
}
for (int i = 0; i < 5; i++){
    cout << n[i] << " ";
}






   


    return 0;
}