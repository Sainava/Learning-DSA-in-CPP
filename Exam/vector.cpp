#include<iostream>
#include<vector>
using namespace std;

template <class T>
void display(vector<T> v){
    for (int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }cout << endl;
}

int main(){
   vector<int> v1;//empty
   vector<int> v2(6,69);
   vector <int> v3(v2);
//    v1.push_back(1);
//     v1.push_back(2);
//     v1.push_back(3);
//     v1.push_back(4);
//     v1.push_back(5);
//     vector<int> :: iterator it=v1.begin();
//     v1.insert(v1.begin(),300);
//    cout << "The size of vector v1 is " << v1.size() << endl;
//    cout << "The capacity of vector v1 is " << v1.capacity() << endl;
//    display(v1);
//    v2.pop_back();
//     cout << "The size of vector v2 is " << v2.size() << endl;
//    cout << "The capacity of vector v2 is " << v2.capacity() << endl;
//    display(v2);
//     v3.push_back(6);
//     cout << "The size of vector v3 is " << v3.size() << endl;
//    cout << "The capacity of vector v3 is " << v3.capacity() << endl;
//     display(v3);
//     v3.resize(5);

//     display(v3);
//      cout << "The size of vector v3 is " << v3.size() << endl;
//    cout << "The capacity of vector v3 is " << v3.capacity() << endl;


    // cout <<endl << endl << endl;
    // v1.back()=100;
    // display(v1);
    // sort(v1.begin(),v1.end());
    //  display(v1);

    vector <int > v4(5,65);
      cout << "The size of vector v4 is " << v4.size() << endl;
      display(v4);
      v4.push_back(1);
      display(v4);
    



    return 0;
}