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
void preorder(struct node *root) 
{
    if (root != NULL) 
    {
        cout << root->data << " -> ";
        preorder(root->left);
        preorder(root->right);
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

node* minValueNode(node* root)
{
    node* current = root;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

node* deleteNode(node* root,int key)
{
    if(root==NULL)
        return root;
    else if(key<root->data)
        root->left=deleteNode(root->left,key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else 
    {
        if (root->left==NULL and root->right==NULL)
            return NULL;
      
        else if (root->left == NULL) 
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) 
        {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = minValueNode(root->right); 
        root->data = temp->data;    // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->data);     // Delete the inorder successor

    }
    return root;
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
    preorder(root);

    root=deleteNode(root,8);
    root=deleteNode(root,3);
    root=deleteNode(root,6);
    cout << "\n\nInorder traversal: ";
    preorder(root);
    
    free_tree(root);
    return 0;
}