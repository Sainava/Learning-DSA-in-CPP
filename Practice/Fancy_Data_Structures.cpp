/*
Create a data structure that allows the following operations.$insert$ $x$ $y$ – insert an object with key x and value y.$get$ $x$ – return the value of an object with key x.$addToKey$ $x$ – add x to all keys in map.$addToValue$ $y$ – add y to all values in map.Time complexity of each operation should be $O(\log(N))$
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;


class fancy_map{
    int keyOffset;
    int valueOffset;

    unordered_map<int,int> m;

    public:
    fancy_map(){
        keyOffset=0;
        valueOffset=0;
    }
    fancy_map(int kOff,int vOff){
        keyOffset=kOff;
        valueOffset=vOff;
    }

    void insert(int key,int value){
        m[key-keyOffset]=value -valueOffset;
    }

    int get(int key){
        auto it=m.find(key - keyOffset);
        if(it==m.end()){
            return -1;
        }
        return m[key - keyOffset] + valueOffset;
    }

    void addToKey(int x){
        keyOffset+=x;
    }

    void addToValue(int x){
        valueOffset+=x;
    }

};

class FancyArray {
    long long valueOffset;
    vector<long long> data;

public:
    FancyArray() : valueOffset(0) {}

    void append(long long x) {
        // store normalized value
        data.push_back(x - valueOffset);
    }

    void addToAll(long long v) {
        valueOffset += v;
    }

    long long get(int i) {
        if (i < 0 || i >= (int)data.size()) return -1; // or handle error
        return data[i] + valueOffset;
    }
};

class FancyMultiset {
    long long valueOffset;
    multiset<long long> ms;  // stores normalized values

public:
    FancyMultiset() : valueOffset(0) {}

    void insert(long long x) {
        ms.insert(x - valueOffset);   // store normalized
    }

    void addToAll(long long v) {
        valueOffset += v;             // O(1), no loop
    }

    long long getMin() {
        if (ms.empty()) return -1;    // or some sentinel
        long long storedMin = *ms.begin();
        return storedMin + valueOffset;
    }
};


int main(){
    fancy_map fm;
    fm.insert(1,2);
    fm.insert(2,3);
    cout<<fm.get(1)<<"\n"; //2
    fm.addToKey(2);
    cout<<fm.get(3)<<"\n"; //2
    fm.addToValue(2);
    cout<<fm.get(3)<<"\n"; //4

    FancyArray fa;
    fa.append(5);
    fa.append(10);
    cout<<fa.get(0)<<"\n"; //5
    fa.addToAll(3);
    cout<<fa.get(1)<<"\n"; //13

    FancyMultiset fms;
    fms.insert(7);
    fms.insert(3);
    cout<<fms.getMin()<<"\n"; //3
    fms.addToAll(4);
    cout<<fms.getMin()<<"\n"; //7

    return 0;
}
