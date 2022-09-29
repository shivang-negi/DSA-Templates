#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void print(Node* n);Node* insert(Node* head,int data,int pos);

int main()
{
    Node* head=new Node();
    Node* second=new Node();
    Node* third=new Node();

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;
    
    third->data=3;
    third->next=NULL;
    
    print(head);
    head=insert(head,0,3);
    print(head);
    return 0;
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
Node* insert(Node* head,int data,int pos)
{
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;
    if(pos==1)
    {
    newNode->next=head;
    head = newNode;
    return head;
    }
    Node* temp=head;        //To find node at which newNode is to be placed
    for(int i=1;i<pos-1;i++)
    {
        if(temp!=NULL)
            temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    return head;
}