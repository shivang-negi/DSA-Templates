#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};
void printLinkedList(Node* n);

Node* middle(Node* root) {
    Node* slow = root,*fast = root;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    Node *head=new Node();
    Node *second=new Node();
    Node *third=new Node();
    
    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

    printLinkedList(head);

    return 0;
}

void printLinkedList(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}