#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node * left;
    Node * right;

    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }        
};

Node * buildTree(Node * root){
    cout<< "Enter the data for the node: " << "\t";
    int data;
    cin >> data;
    Node * root=new Node(data);
    
    if(data==-1){
        return NULL;
    }

    cout<< "Enter the left child of " <<endl;
    root->left=buildTree(root);

    cout<< "Enter the right child of " <<endl;
    root->right=buildTree(root);

    return root;

}
    

int main(){
   
    return 0;
}