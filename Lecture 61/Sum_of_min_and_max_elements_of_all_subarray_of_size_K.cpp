#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int sumOfMinMax(int arr[], int n, int k) {
    if(k > n) {
        return 0; // If k is greater than n, no subarrays of size k can be formed
    }
    int sum = 0;

    deque<int> minDeque, maxDeque;

    // Process the first window to begin with

    for(int i=0;i<k;i++){
        while(!minDeque.empty() && arr[minDeque.back()] >= arr[i]) {
            minDeque.pop_back(); // Maintain increasing order for min
        }
        minDeque.push_back(i);
        while(!maxDeque.empty() && arr[maxDeque.back()] <= arr[i]) {
            maxDeque.pop_back(); // Maintain decreasing order for max      
        }
        maxDeque.push_back(i);
    }

    // Add the first window's min and max to the sum
    sum += arr[minDeque.front()] + arr[maxDeque.front()];

    // Process the rest of the array
    for(int i=k; i<n; i++) {

        // Remove elements that are out of the current window
        if(!minDeque.empty() && minDeque.front()<=i-k){
            minDeque.pop_front();
        }
        if(!maxDeque.empty() && maxDeque.front()<=i-k){
            maxDeque.pop_front();
        }

        // Add the new element to the deques
        while(!minDeque.empty() && arr[minDeque.back()] >= arr[i]) {
            minDeque.pop_back(); // Maintain increasing order for min
        }
        minDeque.push_back(i);
        while(!maxDeque.empty() && arr[maxDeque.back()] <= arr[i]) {
            maxDeque.pop_back(); // Maintain decreasing order for max      
        }
        maxDeque.push_back(i);

        // Add the current window's min and max to the sum
        sum += arr[minDeque.front()] + arr[maxDeque.front()];
    }
    return sum;
}


int main(){
   
    int arr[]={11,3,9,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int result = sumOfMinMax(arr, n, k);
    cout << "Sum of min and max elements of all subarrays of size " << k << " is: " << result << endl;
    return 0;
}