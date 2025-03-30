#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> sieve(int n){
    vector<bool> isPrime(n+1,true);
    vector<int> primes;

    isPrime[0]=isPrime[1]=false;

    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
    return primes;
}

// Function to find all primes in the range [l, h]
void segmentedSieve(int l,int h){
    // Step 1: Find all primes up to sqrt(h)
    int limit =floor(sqrt(h));
    vector<int> primes=sieve(limit);

     // Step 2: Initialize a boolean array for [l, h] and mark all as true (potential primes)
    vector<bool> isPrimeRange(h - l + 1, true);

    // Step 3: Mark multiples of each prime from the base sieve in [l, h] as false
    for(int p:primes){
        for(int j=max(p*p,((l+p-1)/p)*p);j<=h;j+=p){
            isPrimeRange[j-l]=false;
        }
     }

      // Step 4: Print all primes in [l, h]\

    for( int i=0;i<h-l+1 ;i++){
        if(isPrimeRange[i]){
            cout<<i+l<<" ";
        }
    }
    return;

}

int main(){
    int l, h;
    cout << "Enter the range [l, h]: ";
    cin >> l >> h;
    cout << "Prime numbers between " << l << " and " << h << " are: ";
    segmentedSieve(l, h);
    return 0;
}