#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void print(Node* n);Node* insert(Node* head,int data);Node* del(Node* head,int pos);

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
    head=del(head,8);//head,position
    print(head);
    return 0;
}

Node* del(Node* head,int pos)
{
    Node* temp=head;
    if(pos==1)
    {
        head=temp->next;
        free(temp);     //Free old head
        return head;
    }
    for(int i=1;i<pos-1;i++)
        temp=temp->next;
    temp->next=temp->next->next;
    free(temp->next);           //Free deleted node
    return head;
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