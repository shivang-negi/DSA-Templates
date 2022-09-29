#include <iostream>
#include <queue>
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
string serialize(node* root) {
        if (root==NULL) return "";
        string str = "[" + to_string(root->data) + ",";
        queue <node*> q;
        q.push(root);
        while(!q.empty()) {
            node* temp = q.front();
            if(temp->left) {
                q.push(temp->left);
                str = str + to_string(temp->left->data) + ",";
            }
            else str = str + "null,";
            if(temp->right) {
                q.push(temp->right);
                str = str + to_string(temp->right->data) + ",";
            }
            else str = str + "null,";
            q.pop();
        }
        int c = str.size();
        while(c--) if(str[c]>='0' && str[c]<='9') break;
        str[c+1] = ']';
        return str.substr(0,c+2);
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

    cout<<serialize(root)<<endl;
    cout << "Inorder traversal: ";
    inorder(root);
    free_tree(root);
    return 0;
}