#include<iostream>
# include<vector>
using namespace std;

template <class T>
class v{
    public:
    T *arr;
    int size;
    v(int  m) : size(m){
        arr=new T[size];
    }
    T dotproduct(v&v2){
        T d=0;
        for(int i=0;i<size;i++){
        d+=this-> arr[i] *v2.arr[i];
        }
        return d;

    }
};

template <typename T1 ,typename T2=char,class T3=float>
class myclass{
    public :
    T1 data1;
    T2 data2;
    T3 data3;
    myclass(T1 a,T2 b,T3 c): data1(a) , data2(b) , data3(c){
        cout << "The value of data1 is " << data1 << endl;
        cout << "The value of data2 is " << data2 << endl;
        cout << "The value of data3 is " << data3 << endl;

    }
    
};

template < class T>
T funcAvg(T a,T b){
    return (a+b)/2;
}

template <class T>
void swapp( T &a, T &b){
    T temp=a;
    a=b;
    b=temp;
}

template <class T>
class Harry{
    public:
    T data;
    Harry(T a=5){
        data=a;
    }
    void display();
};

template <class T>
 void Harry <T>:: display(){
        cout << "The value of data is "  <<data<< endl;
    }






int main(){
   
//    v<double> v1(3);
//    v1.arr[0]=1.6;
//     v1.arr[1]=2.8;
//     v1.arr[2]=3.8;

//     v<double> v2(3);
//     v2.arr[0]=4.69;
//     v2.arr[1]=5.73;
//     v2.arr[2]=6.91;

//     double d=v1.dotproduct(v2);
//     cout << d << endl;

// myclass<int, double ,double  > obj(35,'c',1.2);

// cout << funcAvg(3.0,5.3)<< endl;

// int x=5,y=6;
// swapp(x,y);
//cout << x << " " << y << endl;
// Harry h(24);
// h.display();
// return 0;
vector<int> v;
v.push_back(1);
v.push_back(54);
v.push_back(34);
v.push_back(89);
v.push_back(5);
v.push_back(0);
v.push_back(7986);
sort(v.begin(),v.end());
for(auto i:v){
    cout <<i << " ";
}

}