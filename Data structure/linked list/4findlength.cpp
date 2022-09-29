#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void print(Node* n);Node* insert(Node* head,int data);int calc(Node* head);

int main()
{
    Node* head=new Node();
    head->data=0;
    head->next=NULL;
    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,3);
    head=insert(head,4);
    head=insert(head,5);
    head=insert(head,6);
    head=insert(head,7);    
    print(head);
    int c=calc(head);
    cout<<c;
    return 0;
}

int calc(Node* head)
{
    int n=0;
    while(head!=NULL)
    {
        n++;
        head=head->next;
    }
    return n;
}
void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
Node* insert(Node* head,int data)
{
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;

    Node* last=head;        //To find node at which newNode is to be placed
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=newNode;
    return head;
}