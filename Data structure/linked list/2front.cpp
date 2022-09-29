#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};


void print(Node* n);
Node* insert(Node* head,int data);

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
    head=insert(head,0);
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
Node* insert(Node* head,int data)
{
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> next = head;
    head = newNode;
    return head;     
}