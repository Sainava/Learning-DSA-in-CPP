#include <iostream>
#include <queue>
#include<stack>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *create(node *root)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    root = new node(data);
    cout << "Enter the left child of " << data << " ->";
    root->left = create(root->left);
    cout << "Enter the right child of " << data << " -> ";
    root->right = create(root->right);

    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl; // Level change
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void reverseLevelOrderTraversal(node *root)
{
    queue<node *> q;
    stack<node *> s;
    q.push(root);
    q.push(NULL);
    // s.push(q.front());
    // s.push(NULL);
    
    
    
    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();
        s.push(temp);

        if (temp == NULL)
        {
            // cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }

    while(!s.empty()){
        node * temp=s.top();
        s.pop();
        if(temp==NULL){
            cout<<endl;
        }
        else{
            cout<<temp->data<<" ";
        }
        
    }
}

void inorderTraversal(node *root){
    if (root==NULL){
        return ;
    }
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(node *root){
    if (root==NULL){
        return ;
    }
    
   
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node *root){
    if (root==NULL){
        return ;
    }
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = NULL;
    // create the tree
    root = create(root);
    // level order traversal
    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);

    cout << "Reverse Level Order Traversal: " << endl;
    reverseLevelOrderTraversal(root);
    cout << endl;

    cout << "Inorder Traversal: " << endl;
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: " << endl;
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: " << endl;
    postorderTraversal(root);
    cout << endl;

    return 0;
}

// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1