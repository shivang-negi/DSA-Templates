#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};
void printLinkedList(Node* n);

//Using hashmap
bool hasCycle(Node *head) 
{
    unordered_set <Node*> hash;
    while(head!=NULL) {
        if(hash.find(head)!=hash.end()) return true;    
        hash.insert(head);
        head=head->next;
    }
    return false;
}

//Using fast and slow pointer
bool hasCycle(Node *head) {
    Node* slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow) return true;
    }
    return false;
}

//Return Start of Linked list cycle using hashmap
Node *detectCycle(Node *head) 
{
    unordered_set <Node*> hash;
    int n=0,i,flag=0;
    Node* t=head;
    Node* cur=head;
    while(t!=NULL)
    {
        if(hash.find(t)!=hash.end())
        {
            cur=t;
            flag=1;
            break;
        }
        hash.insert(t);
        t=t->next;
    }
    if(flag==0)
        return NULL;
    else
        return cur;
}

//Return start of Linked List cycle using fast and slow pointers
Node *detectCycle(Node *head) { 
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { 
            while (head != slow) {
                head = head->next;
                slow = slow->next;
            }
            return head;
        }
    }
    return NULL;
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