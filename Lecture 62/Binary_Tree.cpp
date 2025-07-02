#include<iostream>
#include<queue>
#include<stack>
using namespace std;
/*
| Function                             | Time Complexity | Space Complexity |
| ------------------------------------ | --------------- | ---------------- |
| `buildTree`                          | O(N)            | O(H)             |
| `buildFromLevelOrder`                | O(N)            | O(N)             |
| `levelOrderTraversal`                | O(N)            | O(W)             |
| `inOrder` / `preOrder` / `postOrder` | O(N)            | O(H)             |
| `ReverseLevelOrderTraversal`         | O(N)            | O(N)             |

*/


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
// Function to build a binary tree from user input
Node * buildTree(Node * root){
    cout<< "Enter the data for the node: " << "\t";
    int data;
    cin >> data;
    root=new Node(data);
    
    if(data==-1){
        return NULL;
    }

    cout<< "Enter the left child of " <<endl;
    root->left=buildTree(root);

    cout<< "Enter the right child of " <<endl;
    root->right=buildTree(root);

    return root;

}
    

// Level order always requires a queue to store the nodes at each level
void levelOrderTraversal(Node * root){
    if(root==NULL){
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node * temp=q.front();
        q.pop();
        
        if(temp==NULL){
            //The previous level is done
            cout <<endl;
            if(!q.empty()){ // queue still has child nodes
                q.push(NULL); // Push a NULL to mark the end of the next level
            }
        }else{
            cout << temp->data << " ";
            if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        }
        
    }
    
}
// Traversals of the binary tree
void inOrder(Node * root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<< root->data << " ";
    inOrder(root->right);
 }
// Preorder traversal visits the root first, then left subtree, then right subtree
void preOrder(Node * root){
    if(root==NULL){
        return;
    }
    cout<< root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
 }
// Postorder traversal visits the left subtree first, then right subtree, then root
 void postOrder(Node * root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<< root->data << " ";
 }
// Reverse level order traversal uses a queue to traverse the tree and a stack to reverse the order
 void ReverseLevelOrderTraversal(Node * root){
    if(root==NULL){
        return;
    }

    queue<Node *> q;
    stack<Node *> s; // Stack to reverse the order

    q.push(root);
    q.push(NULL); // To mark the end of the level

    while(!q.empty()){
        Node * temp=q.front();
        q.pop();
        s.push(temp); // Push to stack to reverse order
        if(temp==NULL){
             // The previous level is done
            if(!q.empty()){ // queue still has child nodes
                q.push(NULL); // Push a NULL to mark the end of the next level
            }
            
        }else{
            if(temp->left){ // Right child first for reverse order
            q.push(temp->left);
            }
            if(temp->right){
            q.push(temp->right);
            }
        }
        
    }

    while(!s.empty()){
        if(s.top() == NULL){

            cout << endl;// Skip NULL nodes
        }else{
            cout << s.top()->data << " ";
        }
         // Pop from stack to print in reverse order
        s.pop();
    }
}


void buildFromLevelOrder(Node * &root){
    queue<Node *> q;

    cout << "Enter data for the root node: ";
    int data;
    cin >> data;
    root = new Node(data);

    q.push(root);

    while(!q.empty()){
        Node * temp =q.front();
        q.pop();

        cout << "Enter left child of " << temp->data << ": ";
        int leftData;
        cin >> leftData;
        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << ": ";
        int rightData;
        cin >> rightData;
        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}




// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
int main(){
   Node * root=NULL;

    cout<< "Building tree from user input: " << endl;
    buildFromLevelOrder(root);
    cout<< "\nLevel order traversal of the tree is: " << endl;
    levelOrderTraversal(root);


   /*
   root=buildTree(root);
   cout<< "\nLevel order traversal of the tree is: " << endl;
   
   levelOrderTraversal(root);

    cout<< "\nInorder traversal of the tree is: " << endl;
    inOrder(root);

    cout<< "\nPreorder traversal of the tree is: " << endl;
    preOrder(root);

    cout<< "\nPostorder traversal of the tree is: " << endl;
    postOrder(root);

    cout<< "\nReverse Level order traversal of the tree is: " << endl;
    ReverseLevelOrderTraversal(root);
    */
    return 0;
}