#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>

using namespace std;

void arr(){  

    /* WRONG INITIALISATION
        array<int>a;
        array<int>b={1,2,3,4};

    FOR CORREECT INITIALISATION YOU HAVE TO MENTION THE SIZE
    */ 

   //CORRECT INITIALISATION   int array[]={1,2,3};
   
    array<int,4>a={1,2,3,4};

     for(int i=0;i<a.size();i++){
            cout << a[i]<< " ";
    }
    cout << endl;

    cout << "Element at index 2 is : "<< a.at(2)<<endl;

    cout << "Empty or not "<< a.empty()<< endl;// Returns bool 1 if empty and 0 if not not empty;
    //Will always return 0 as array is almost never empty as during initialisation it has garbage values ;
    //only array<int,0>a will give 1 as then it is empty;

    cout << "Frist elemnt : " << a.front()<< endl;
    cout << "Last element : " << a.back()<< endl;

    /*   ARRAY  HAS NO FUNCTION CAPACITY 
    cout << "Capacity of array: "<< a.capacity(); -------> GIVES ERROR  ;
    */
}

void vec(){

         /* WRONG INITIALISATION
        vector<int,4>v; CANNOT GIVE SIZE LIKE THIS 

        */

         vector<int> a(5,1);// Size and Capacity is 5 and all elements initiales by one 
         cout<< "INITIAL Capacity of vector  : " << a.capacity()<< endl;
         cout << "SIZE : " << a.size() << endl;
         for(int i=0;i<a.size();i++){
            cout << a[i] << " ";
        }
        cout <<endl;

        vector<int>b(a); // Vector a is copied to vector b
        for(int i=0;i<b.size();i++){
            cout << b[i] << " ";
        }
         cout <<endl;

        vector<int>v;

        //(does not mean the number of elements just the memory space available)
        cout<< "INITIAL Capacity of vector  : " << v.capacity()<< endl;

        v.push_back(1);
        cout<< "After 1 element  Capacity of vector  : " << v.capacity()<< endl;

        v.push_back(2);
        cout<< "After 2 element  Capacity of vector  : " << v.capacity()<< endl;

        v.push_back(3);
        cout<< "After 3 element  Capacity of vector  : " << v.capacity()<< endl;

        cout << "SIZE : " << v.size() << endl;

        cout << "Element at index 2 is : "<< v.at(2)<<endl;

        cout << "Frist elemnt : " << v.front()<< endl;
        cout << "Last element : " << v.back()<< endl;

        cout << "Before pop"<< endl;
        //First Method of Traverse
        for(int i=0;i<v.size();i++){
            cout << v[i] << " ";
        }
        cout<<endl;

        v.pop_back();

        cout << "After pop"<< endl;
        //Another mehtod of traverse
        for(int i:v){
            cout << i<< " ";
        }

        cout << "Before Clear Size is :" << v.size()<<endl;
        v.clear();
        cout << "Before Clear Size is :" << v.size()<<endl;

}

void deq(){

    deque<int> d;
    d.push_back(2);
    d.push_front(1);
    d.push_back(3);

    cout<< "The element at index 1 is : "<< d.at(1)<< endl;

    cout << "Frist elemnt : " << d.front()<< endl;
    cout << "Last element : " << d.back()<< endl;

    cout << "Empty or not "<< d.empty()<< endl;

    cout<< "Before deletion: "<< endl;
    for(int i:d){
        cout <<i << " ";
    }
    cout<<"size: " << d.size()<<endl;
    //d.pop_front();
    //d.pop_back();
    
    d.erase(d.begin(),d.begin() + 1);// Iteration to =d.begin() to < d.end() 

    cout<<"After erase from v.begin to v.end : "<<endl;
    for(int i:d){
        cout <<i << " ";
    }
    cout<<"size: " << d.size()<<endl;

    cout<<"Remember deletion the size is zero but memory allocated is not zero" << endl;
    cout<< "Deque does not have capacity memeber"<< endl; 

}
void lst(){

    // This is allowed 
    // list<int> l={1,2,3,4,5);

    list<int> l;

    list<int> a(5,100);

    l.push_back(2);
    l.push_front(1);
    l.push_back(3);

    cout << "Frist elemnt : " << l.front()<< endl;
    cout << "Last element : " << l.back()<< endl;

    cout << "Empty or not "<< l.empty()<< endl;

    cout<< "Before deletion: "<< endl;
    for(int i:l){
        cout <<i << " ";
    }
    cout<<"size: " << l.size()<<endl;

    cout << "l.erase(l.begin(),l.begin() + 1) \nThe above is not possible as in list uses bidirectional iterators, which allow moving forward and backward one step at a time, but do not support arithmetic operations like + or -. In contrast, containers like std::vector or std::deque support random access iterators, which allow such operations. "<<endl;
    l.erase(l.begin());
    cout<<"After erase passing parameter l.begin(): "<<endl;
    for(int i:l){
        cout <<i << " ";
    }
    cout<<"size: " << l.size()<<endl;
    cout<< "First element is deleted"<< endl;

}

void stk(){
    stack<string> s;
    
    s.push("Man utd ");
    s.push("Man City");
    s.push("Liverpool");

    cout << "Top element: " << s.top()<< endl;

    cout << "The size of the stack : " << s.size()<< endl;;
    s.pop();

    cout << "Top element : " << s.top()<< endl;

    cout << "The size of the stack : " << s.size()<< endl;;

    cout << "Empty or not : " << s.empty()<< endl;
}

void qu(){
    queue<string> q;

    q.push("Old");
    q.push("Country");
    q.push("Roads");

    cout << "Before pop Size is : " << q.size()<< endl;
    cout << "First element is : " << q.front() << endl;
    q.pop();
     cout << "After pop Size is :"<< q.size()<< endl;
    cout << "First element is : " << q.front() << endl;

}

void priority(){
    //  MAX HEAP : Largest Element has the highest priority
    priority_queue<int> maxi;

    //MIN HEAP : Smallest element has the highest priority

    priority_queue< int, vector<int> , greater<int> >  mini;

    maxi.push(1);
    maxi.push(5);
    maxi.push(3);
    maxi.push(8);
    maxi.push(7);

    int n=maxi.size();

    cout<< "MAX HEAP" << endl;
    for(int i=0;i<n;i++){
        cout << maxi.top() << " ";
        maxi.pop();
    }cout <<endl;

    mini.push(1);
    mini.push(5);
    mini.push(3);
    mini.push(8);
    mini.push(7);

    n=mini.size();
    cout<< "MIN HEAP" << endl;
    for(int i=0;i<n;i++){
        cout << mini.top() << " ";
        mini.pop();
    }cout << endl;

    cout << "Are the heaps empty: "  << mini.empty() << endl;

}

void st(){
    // Does not store multiple entries of the same element 
    //ordered set or default set returns the elements in ascending order
    //Un-orrdered set returns the elements in random  order
    cout << "Time complexity of insert,find erase and count -> O(logn) "<< endl;
    cout << "Time complexity of size,begin,end and empty -> O(1) "<< endl;

    set<int> s;
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(7);
    s.insert(7);
    s.insert(4);
    s.insert(9);
    s.insert(65);
    s.insert(65);

    cout <<"before deletion (or erase) The size is :" << s.size()<<endl;
    for(auto i:s){// you can use int i
        cout<< i<< " " ;
    }cout<< endl;

    set<int>:: iterator it =s.begin();
    it++;
    //it=it+2; NOT ALLOWED

    s.erase(it);//deletes the second  element;

    cout <<"after deletion (or erase) The size is :" << s.size()<<endl;
    for(auto i:s){// you can use int i
        cout<< i<< " " ;
    }cout<< endl;

    cout<< "7 is present or not : " << s.count(7)<<endl;//returns 1 if present ,returns 0 if not
    cout<< "-7 is present or not : " << s.count(-7)<<endl;

    set<int> :: iterator itr=s.find(7); // .find() returns an iterator pointing to the location of the element
    //Iterators are similar to pointers but they have differences as some iterators only support and decrement and not other arithmetic operations

    cout<< "Printing numebrs after 7"<<endl;
    for (auto i=itr;i!=s.end();i++){
        cout << *i<<endl;
    }
}

void mp(){
//In case of map time complexity of insert,erase,count and find is O(logn)
//In case of  ORDERED map time complexity of Search is O(logn)
//In case of UNORDERED map time complexity of Search is O(1)

    map<int,string> m;
    
    m[10]="Messi";
    m[7]="Ronaldo";
    m[11]="Neymar";

    m.insert({14,"Cruyff"});

    // In case of ORDERED maps ,the elements are stored in sorted order based on the keys
    // Not true for UNORDERED maps.
    cout << "Before erase Size is :"<< m.size()<<endl; 
    for(auto i:m){
        cout<< i.first<<" " << i.second<< endl;
    }

    cout<< "Finding 9--> " << m.count(9)<< endl;

    m.erase(11);
    cout<<"--------------------------------------"<< endl;
    cout << "After erase Size is :"<< m.size()<<endl; 
    for(auto i:m){
        cout<< i.first<<" " << i.second<< endl;
    }
    cout<<"--------------------------------------"<< endl;

   auto it=m.find(10);//Returns an ITERATOR

   for(auto i=it;i!=m.end();i++){
        cout<< (*i).first<< endl;
   }




}

int main(){
   // arr();
    //vec();
    //deq();
    //lst();
    //stk();
    //qu();
   //priority();
    //st();
    //mp();


//     cout<< "v.begin() and v.end() are used to iterate through the data structures and manage ranges :" << endl;
//     cout << "v.begin() :  This function returns an iterator pointing to the first element of the container" << endl;
//     cout << "v.end(): This function returns an iterator pointing one position past the last element " << endl;
}