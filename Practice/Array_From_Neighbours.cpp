#include<iostream>
using namespace std;
#include<vector>

vector<int> buildFromNeighbours(vector<int> &arr){
    vector<int> b;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int left= (i-1<0) ? 0: arr[i-1];
        int right=(i+1>=n)? 0: arr[i+1];
        b.push_back(left+arr[i] +right);
    }
    return b;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    vector<int> result=buildFromNeighbours(arr);
    for(int i:result){
        cout<<i<<" ";
    }
    return 0;
}