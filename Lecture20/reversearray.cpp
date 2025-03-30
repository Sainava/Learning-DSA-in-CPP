#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

void reverse(vector<int>& v,int n){

//METHOD 1

//    int s=0;
//    int e=n-1;

//    while(s<=e){
//         swap(v[s],v[e]);
//         s++;
//         e--;
//     }

// METHOD 2

for (int i=0;i<n/2;i++){
    swap(v[i],v[n-1-i]);
}

}
void print(vector<int> &v){
    for(int i:v){
        cout << i<<" ";
    }
    cout<< endl;
}

int main(){

    vector<int> v;

    v={2,6,4,5,1};
   
   cout << "Original Array"<<endl;
    print(v);

   reverse(v,5);

   cout<< "After Reversal"<<endl;
   print(v);

   return 0;
}