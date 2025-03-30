#include<iostream>
using namespace std;

long long int sqrtint(int n){
    int s=0;
    int e=n;
    long long int mid=s+(e-s)/2;
    long long ans=-1;
    while(s<=e){
        long long int sqr=mid*mid;
        if (sqr==n){
            ans=sqr;
            return mid;
        }

        else if(sqr<n){
            ans=mid;
            s=mid +1;

        }

        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return  ans;
}

double moreprecise(int tempsol,int n,int precision){
    float factor=1;
    double ans=tempsol;
    
    for(int i=0;i<precision;i++){
        factor=factor/10;
        for(double j=ans; j*j<=n; j=j+factor ){
            ans=j;
        }
    }

    return ans;
}

int main(){
    int n;
    cout << "Enter the number : " ;
    cin >> n;
   
    long long int tempsol = sqrtint(n);
    
    int precise;
    cout << "Enter the precision : ";
    cin >> precise;

    double ans=moreprecise(tempsol,n,precise);
    cout<< "The square root is : "  << ans<< endl;


    
}