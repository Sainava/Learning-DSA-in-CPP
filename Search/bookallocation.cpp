#include<iostream>
using namespace std;

bool ispossible(int arr[],int n ,int m ,int mid){
    int studentCount=1;
    int PageSum=0;

    for (int i=0;i<n;i++){

        if (PageSum+arr[i] <=  mid ){
            PageSum += arr[i]; 
        }

        else { 
            studentCount++;
                if(studentCount>m || arr[i]>mid){
                        return false;
                        
                 }
                PageSum=arr[i];
        }
    }
    return true;
}

int bookallocate(int arr[],int n,int m){
    int s=0;
    int sum=0;

    for(int i=0;i < n;i++){
        sum += arr[i];
    }

    int e=sum;
    int mid=s+(e-s)/2;
    int ans=-1;

    while(s<=e){
        if (ispossible(arr,n,m,mid)){
                ans=mid;
                e=mid-1;
        }

        else{
            s=mid+1;
        }

        mid=s+(e-s)/2;

    }

    return ans;
}


int main(){
    int arr[4]={10,20,30,40};
    cout<< "The required answer is : " << bookallocate(arr,4,2);
}