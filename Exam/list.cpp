#include<iostream>
#include<list>
using namespace std;
template <class T>
void display(list<T> &l){
    typename list<T> :: iterator it;
    it=l.begin();
    for (;it!=l.end();it++){
        cout << *it  << " ";
    }cout << endl;
}


int main(){
   list<int> l1;
    list<int> l2;
    // cout << l2.size() << endl;
    // display(l2);

    // cout << l2.max_size() << endl;
    l1.push_back(23);
    l1.push_back(24);
    l1.push_back(25);
    //display(l1);
    l1.pop_front();
    l1.insert(l1.begin(),3,22);
     //display(l1);
     //l1.sort();
        display(l1);

    l2.push_back(11);
    l2.push_back(65);
    l2.push_back(23);
    l2.push_back(45);
    l2.push_back(23);
    display(l2);
    // l1.sort();
    // l2.sort();
    // l2.merge(l1);
    //display(l2);
    //list<int> :: iterator it;
    // it=l1.begin();
    // it++;
    // it++;
    auto it=next(l1.begin(),2);
    
    

    l1.splice(it,l2);
    display(l1);

    return 0;
}