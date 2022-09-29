#include <iostream>
using namespace std;

class node 
{
    public:
        int data;
        node *left, *right;
};

bool isSameTree(node* p, node* q) 
    {
        if(p==NULL && q==NULL)
            return true;
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL))
            return false;
        if(p->data != q->data)
            return false;
        return (isSameTree(p->left,q->left));return(isSameTree(p->right,q->right));
    }



    bool check(node* p,node* q)
    {
        if(p==NULL && q==NULL)
            return true;
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL))
            return false;
        if(p->data!=q->data)
            return false;
        return check(p->left,q->right) && check(p->right,q->left);
    }
    bool isSymmetric(node* root) 
    {
        if(root==NULL)
            return true;
        bool x=check(root->left,root->right);
        return x;
    }