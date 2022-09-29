#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void print(Node* n);Node* insert(Node* head,int data);int check(Node* head);

int main()
{
    Node* head=new Node();
    int n,k;
    cout<<"Enter no. of nodes in Linked list:";
    cin>>n;
    cout<<"Enter nodes values:";
    for(int i=0;i<n;i++)
    {
        cin>>k;
        if(i==0)
            head->data=k;
        else
            head=insert(head,k);
    }   
    print(head);
    int c=check(head);
    if(c==0)
        cout<<"False";
    else
        cout<<"True";
    return 0;
}

int check(Node* head)
{
    Node* temp=head;
    stack <int> st;
    while(temp!=NULL)
    {
        st.push(temp->data);
        temp=temp->next;
    }
    while(head!=NULL)
    {
        int x=st.top();
        if(x!=head->data)
            return 0;
        st.pop();
        head=head->next;
    }
    return 1;
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