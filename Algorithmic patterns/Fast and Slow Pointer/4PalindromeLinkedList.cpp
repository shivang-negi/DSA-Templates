#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};
void printLinkedList(Node* n);

//O(N) Time O(N) Space
bool isPalindrome(Node* head) {
    vector<int> arr;
    int n = 0;
    while(head) {
        arr.push_back(head->data);
        head = head->next;
        n++;
    }
    int l = 0;
    n--;
    while(l<n) 
        if(arr[l++]!=arr[n--]) return false;
    return true;
}

//O(N) Time O(1) Space
bool isPalindrome(Node *head) {
    Node *fast=head,*slow=head;
    while(fast && fast->next) {                  
        slow=slow->next;
        fast=fast->next->next;
    }
    Node *rev_node=slow,*prev=NULL,*cur=slow;
    while(rev_node) {
        cur=rev_node->next;
        rev_node->next=prev;
        prev=rev_node;
        rev_node=cur;
    }
    slow=prev;
    while(slow && head) {
        if(slow->data!=head->data) return false;
        slow=slow->next;
        head=head->next;
    }
    return true;
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