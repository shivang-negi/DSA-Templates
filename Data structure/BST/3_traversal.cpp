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
void preorder(struct node *root) 
{
    if (root != NULL) 
    {
        cout << root->data << " -> ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root) 
{
    if (root != NULL) 
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " -> ";
    }
}

node *insert(node *node, int data) 
{
    if (node == NULL) 
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    return node;
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

    cout << "Inorder traversal: ";
    inorder(root);cout<<endl;
    
    cout << "Preorder traversal: ";
    preorder(root);cout<<endl;
    
    cout << "Postorder traversal: ";
    postorder(root);cout<<endl;
    
    free_tree(root);
    return 0;
}