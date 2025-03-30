#include<iostream>
using namespace std;

bool linearsearch(int arr[],int size,int key){
            for(int i=0;i<size;i++){
                if(arr[i]==key){
                    return 1;
                }
            }
            return 0;
}

int main(){

    int arr[10]={5,7, -2, 10, 22 ,-2 , 0, 5 ,22 ,1};

    int key;
    cout << "Enter element you wish to search " << " ";
    cin >> key;

    bool ans=linearsearch(arr,10,key);
    
    if(ans){
        cout << "The element is present" << endl;
    }
    else{
        cout << "The element is not  present" << endl;
    }

}