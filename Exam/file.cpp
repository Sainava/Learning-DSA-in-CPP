#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
// #include<istream>
// #include<ostream>
using namespace std;

int main(){
   //ofstream out("Text1.txt");//using constructor
//     ofstream out;
//     out.open("Text1.txt");//using member function

//     // Taking input from the user 
//     // string line ;
//     //cout<<"Enter the line to write in the file: ";
//    // getline (cin,line );

//     out <<"YO ho ho ho YO ho   ho ho "<<endl;
//     out << "Crazy aint it " << endl;
//     out <<"This is a text file ladies and gentlemen"<<endl;

//     cout << out.tellp() <<endl;
//     (out.seekp(-12,fstream::end));
//     cout << out.tellp() <<endl;
//     out.seekp(7,fstream::cur);
//     out << "Sainava Modak is the GOAT";
//      cout << out.tellp() <<endl;

//     out.close();

    // ifstream in("superman.txt");
    // string content ;
    // // getline(in,content);
    // // cout << content << endl;
    // // cout<< (in.tellg())<<endl;
    // // in.seekg(12,fstream::end);
    // // cout<< (in.tellg())<<endl;
    // // getline(in,content);
    // // cout << content << endl;

    // // while(in.eof()==0){
    // //     getline(in,content);
    // //     cout << content << endl;
    // // }
    // getline(in,content);
    // cout << content << endl;
    // getline(in,content);
    // cout << content << endl;
    // cout <<in.tellg()<<endl;
    // in.seekg(-122,fstream::end);
    // cout <<in.tellg()<<endl;
    // getline(in,content);
    // cout << content << endl;
    // in.close();

    // ofstream file("yo.txt");
    // file.seekg(0,ios::end);
    // int size = file.tellg();
    // cout << size << endl;
    // cerr<<"YOYOBIGO "<<endl;



    //METHOD 1
    // ifstream fin("superman.txt");
    // if (fin.is_open()==0){
    //     cerr<< "File not found"<<endl;
    // }
    // string str;
    // string temp;
    // while(getline (fin,temp)){
    //     str.append(temp);
    //     str.append("\n");
    // }
    // fin.close();

    // ofstream fout("Onepiece.txt");
    // fout <<str;
    // fout.close();


    // ifstream fin("superman.txt");

    // if (fin.is_open()==0){
    //     cerr<< "File not found"<<endl;
    // }
    // ofstream fout("Onepiece.txt",ios::app);
    // string str;
    // fout <<endl;
    // while(getline(fin,str)){
    //     fout <<str<<endl;
    // }
    // char ch;
    // fin>>ch;
    // cout<<ch;

    // fin.close();
    //fout.close();

    // ifstream fin("superman.txt");
    // char ch[100];
    // fin>> ch;
    // cout << ch << endl;
    // cout.width(5);
    // cout.setf(ios::internal | ios:: showpos);
    // cout<<-10;
    // cout.width(-5);
    // cout<<20;
    cout.setf(ios::hex,ios::basefield);
    cout<< setw(5)<<100<<endl;


    return 0;
}