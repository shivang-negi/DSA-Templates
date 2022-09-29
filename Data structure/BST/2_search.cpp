#include <iostream>
using namespace std;

class node 
{
    public:
        int data;
        node *left, *right;
};

node *newNode(int item) 
{
    node *temp = new node();
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root) 
{
    if (root != NULL) 
    {
        inorder(root->left);
        cout << root->data << " -> ";
        inorder(root->right);
    }
}

node *insert(struct node *node, int data) 
{
    if (node == NULL) 
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    return node;
}
bool search(node* root,int data)
{
    if(root==NULL)
        return false;
    else if(root->data==data)
        return true;
    else if(data<root->data)
        return search(root->left,data);
    else
        return search(root->right,data);
}

void free_tree(node * root)     //To prevent memory leak
{
    if (root != NULL) 
    {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}
int main() 
{
    node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    cout<<search(root,14);
    free_tree(root);
    return 0;
}