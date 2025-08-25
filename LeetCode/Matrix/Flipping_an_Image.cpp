/*
Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.

For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

For example, inverting [0,1,1] results in [1,0,0]
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverse(vector<int> &row){
        int i=0;
        int j=row.size()-1;

        while(i<j){
            swap(row[i],row[j]);
            i++;
            j--;
        }

    }

    void invert(vector<int> &row){
        for(int i=0;i<row.size();i++){
            row[i]=!row[i];
        }
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i=0;i<image.size();i++){
            reverse(image[i]);
            invert(image[i]);
        }
        //TC:O(nxn)
        return image ;
    }
    
};