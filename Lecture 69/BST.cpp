#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int d){
        data=d;
        left=nullptr;
        right=nullptr;
    }

    ~Node(){
        if(left){
            delete left;
        }
        if(right){
            delete right;
        }
    }
};

Node* insertToBST(Node* &root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    if(data<root->data){
       root->left= insertToBST(root->left,data);
    }else{
       root->right= insertToBST(root->right,data);
    }

    return root;
}
    

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data!=-1){
        root=insertToBST(root,data);
        cin >> data;
    }
}

void levelOrderTraversal(Node * &root){
    if(root==NULL){
        return;
    }
    queue<Node * > q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node * temp=q.front();
        q.pop();

        if(temp==NULL){
            cout << endl;
            if(!q.empty()){
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

void inorder(Node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int FindMax(Node * root){
    if(root==NULL){
        return INT_MIN; // Return a very small value if the tree is empty
    }

    Node * temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
}

int FindMin(Node * root){
    if(root==NULL){
        return INT_MAX; // Return a very large value if the tree is empty
    }

    Node * temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}   

int findPred(Node * root){ // Basically the maximum element from the left subtree
    if (root==NULL){
        return -1;
    }

    Node * temp=root->left;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
}

int findSucc(Node * root){ // Basically the minimum element from the right subtree
    if (root==NULL){
        return -1;
    }

    Node * temp=root->right;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}   


Node *  Deletion(Node * &root, int data) {
    if(root==NULL){
        return NULL; // If the tree is empty, return NULL
    }

    // If the data to be deleted is found
    if(root->data==data){
        // Case 1 : If Deleted Node is a Leaf Node 
        if(root->left==NULL && root->right==NULL){
           delete root;
           return NULL;
        }

        // Case 2 : If Deleted Node has one child 
        if(root->left==NULL || root->right==NULL){
            Node * temp=root;
            root->left==NULL ? root=root->right : root=root->left;
            temp->right=temp->left=NULL; // Disconnect the child node from the deleted node because the destructor defined in class Node deletes all children too
            delete temp;
            return root;
        }

        // Case 3 : If Deleted Node has two children
        if(root->left!=NULL && root->right!=NULL){
            // Find the inorder predecessor or successor
            int inorderPred=findPred(root);
            root->data=inorderPred; // Replace the data with the predecessor
            root->left=Deletion(root->left,inorderPred); // Delete the predecessor node
            return root;
        }
    
    }
    // If the data is less than the root, go to the left subtree
    else if(data< root->data){
        root->left=Deletion(root->left, data);
    } 
    else { // If the data is greater than or equal to the root, go to the right subtree
        root->right=Deletion(root->right, data);
    }
    return root;
}   

/*
Yes, the cin object in C++ generally reads one number at a time when used with the extraction operator >>. 
When you use cin >> num, where num is a numeric variable, cin reads characters from the input stream until it encounters a whitespace character (like a space or newline) or an invalid character for the type of num.
 It then converts the sequence of valid characters into a number and stores it in num. 
*/

//If you input 123 456, cin >> num1 >> num2; would store 123 in num1 and 456 in num2. 

//10 8 21 7 27 5 4 3 -1

int main(){
    Node * root=NULL;

    cout << "Enter the data to create the BST " << endl;
    takeInput(root);

    cout << "Level Order Traversal of the BST: " << endl;
    levelOrderTraversal(root);

    cout << "Inorder Traversal of the BST: " << endl;
    inorder(root);

    // For Deletion first break it down into steps;

    int max=FindMax(root);
    cout << "\nMaximum value in the BST: " << max << endl;

    int min=FindMin(root);
    cout << "Minimum value in the BST: " << min << endl;

    int inorederPred=findPred(root);
    cout << "Inorder Predecessor of  root the BST: " << inorederPred << endl;

    int inorderSucc=findSucc(root);
    cout << "Inorder Successor of root the BST: " << inorderSucc << endl;

    int dataToDelete;
    cout << "Enter the data to delete from the BST: ";
    cin >> dataToDelete;
    root=Deletion(root, dataToDelete);
    cout << "Data deleted successfully." << endl;

    cout << "Level Order Traversal of the BST after deletion: " << endl;
    levelOrderTraversal(root);

    cout << "Time complexity for insertion , searching and deletion in BST is O(logn) in average case and O(n) in worst case where n is the number of nodes in the tree." << endl;

    // Test for cin reading numbers

    // int num1,num2,num3,num4,num5;
    // cout << "Enter five numbers separated by spaces  ";
    // cin >> num1;
    // cin >> num2;
    // cin >> num3;
    // cin >> num4;
    // cin >> num5;
    // cout << "You entered: " << num1 << " " << num2 << " " << num3 << " " << num4 << " " << num5 << endl;

   return 0;
}

