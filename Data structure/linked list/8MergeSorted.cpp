#include<bits/stdc++.h>     //Merging two sorted linked list
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void print(Node* n);Node* insert(Node* head,int data);Node* calc(Node* head1,Node* head2);

int main()
{
    Node* head1=new Node();
    int n,k;
    cout<<"Enter no. of nodes in Linked list 1:";
    cin>>n;
    cout<<"Enter nodes values:";
    for(int i=0;i<n;i++)
    {
        cin>>k;
        if(i==0)
            head1->data=k;
        else
            head1=insert(head1,k);
    }   
    Node* head2=new Node();
    cout<<"Enter no. of nodes in Linked list 2:";
    cin>>n;
    cout<<"Enter nodes values:";
    for(int i=0;i<n;i++)
    {
        cin>>k;
        if(i==0)
            head2->data=k;
        else
            head2=insert(head2,k);
    }   
    print(head1);
    print(head2);
    Node* head = new Node();
    head=calc(head1,head2);
    print(head);
    return 0;
}

Node* calc(Node* head1,Node* head2)
{
    Node head;      //Dummy variable whose next node would be result.
    Node *tail = &head; //Pointer holding dummy, will travel from node to node 
                        //forming the result.
        
        while (head1 && head2) //Will run till one of the list is NULL
        {
            if (head1->data < head2->data)
            {
                tail->next = head1;
                head1 = head1->next;
            } 
            else
            {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }
        tail->next = head1 ? head1 : head2; //If list1 is empty,append list2 and vice versa
        return head.next;
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