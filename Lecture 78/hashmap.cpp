#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
   unordered_map<string,int> m; // Unordered map is implemented using hash table

   // 3 ways of insertion

   pair<string,int> p1=make_pair("Messi",10);
   m.insert(p1);

    pair<string,int> p2("Ronaldo",7);
    m.insert(p2);

    m["Neymar"]=11; // This will create a new key-value pair if the key does not exist or update the value if the key exists

    // The keys need to be unique in a map, if you try to insert a duplicate key, it will just update the value   

    // Search -> 2 ways

    cout << m["Messi"] <<endl; 
    cout << m.at("Ronaldo") << endl; // at() will throw an exception if the key does not exist

    // cout << m.at("Mbappe") << endl; // Uncommenting this will throw an exception
    cout << m["Mbappe"] << endl; // This will create a new key-value pair with value 0

    cout << m.at("Mbappe") << endl; // This will not throw an exception, but will return 0

    // Check if a key exists
    if(m.count("Neymar")){
        cout << "Neymar exists in the map" << endl;
    }else{
        cout << "Neymar does not exist in the map" << endl;
    }


    // size of the map
    cout << "Size of the map: " << m.size() << endl;

    // print all key-value pairs
    for (auto &pair: m){
        cout << pair.first << " : " << pair.second << endl;
    }

    // Delete a key-value pair
    m.erase("Neymar");

    // Another way to iterate through the map

    cout << "After deleting Neymar:" << endl;
    unordered_map<string,int> :: iterator it = m.begin();

    while(it!=m.end()){
       cout << it->first << " : " << it->second << endl;
       it++;
    }

    // The order is random and not sorted, because it is an unordered map , it is also NOT stored in the order of insertion

    // But if i do

    cout << "SORTED MAP" << endl;
    map<string,int> m2; // This is a sorted map, it will store the elements in sorted order of keys
    m2["Messi"]=10;
    m2["Ronaldo"]=7;
    m2["Neymar"]=11;
    m2["Mbappe"]=30;

    cout << "Sorted map:" << endl;
    for (auto &pair: m2){
        cout << pair.first << " : " << pair.second << endl;
    }
    // Not order of insertion, but sorted by keys (here alphabetically)

    cout << "In unordered map, the time complexity for insertion,deletion and searching is O(1) on average " << endl;
    cout << "In sorted map, the time complexity for insertion,deletion and searching is O(log n) on average " << endl;
    return 0;
}