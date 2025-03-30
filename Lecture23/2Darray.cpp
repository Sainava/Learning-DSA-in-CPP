#include<iostream>
using namespace std;

bool isPresent(int arr[][4],int target, int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==target){
                return 1;
            }
        }
    }
    return 0;

}

void largestRow(int arr[][4],int row,int col){
 int max=INT_MIN;
 int maxrow=-1;
 for(int i=0;i<row;i++){
    int sum=0;
    for(int j=0;j<col;j++){
      sum+=arr[i][j];
    }
    if (sum>max){
        max=sum;
        maxrow=i;
    }
 }
   cout << "The largest row is : " << maxrow << " and the sum is : " << max << endl;
}


int rowWiseSum(int arr[][4],int row,int col){
  int sum=0;
  for(int i=0;i<row;i++){
   
    for(int j=0;j<col;j++){
      sum+=arr[i][j];
    }
    }
    return sum;
}

void sumEachRow(int arr[][4],int row,int col){
 
  for(int i=0;i<row;i++){
    int sum=0;
    for(int j=0;j<col;j++){
      sum+=arr[i][j];
    }
    cout << "The sum of the row " << i << " is : " << sum << endl;
  }
}

int main(){
    //int arr[3][4];
    //int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};// Enters elements row wise,[0][0]then [0][1] then [0][2] then [0][3] then [1][0] and so on
    int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};// Enters elements row wise,first row then second row and so on

    // cout << "Enter the values" << " ";
    // // Input the values row vise
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //         cin >> arr[i][j];
    //     }
    // }

    // input the values column vise
    // for(int j=0;j<4;j++){
    //     for(int i=0;i<3;i++){
    //         cin >> arr[i][j];
    //     }
    // }

    //output the values  vise
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // cout << "Enter the target value" << " ";
    // int target;
    // cin >> target;
    // isPresent(arr,target,3,4)?cout << "Present":cout << "Not Present";

    sumEachRow(arr,3,4);
    cout << "The row wise sum of the elements is : " << rowWiseSum(arr,3,4)<< endl;
    largestRow(arr,3,4);
    

    

    return 0;
}

