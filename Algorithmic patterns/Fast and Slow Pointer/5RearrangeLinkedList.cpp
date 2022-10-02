#include<bits/stdc++.h>
using namespace std;

/*
Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln. Rearrange the nodes in the list 
so that the new formed list is: L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2.
You are required to do this in place without altering the nodes’ values. 

Input:  1 -> 2 -> 3 -> 4
Output: 1 -> 4 -> 2 -> 3

Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 1 -> 5 -> 2 -> 4 -> 3
*/

struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


//Using Vector O(n) Space O(n) Time 
void *inPlace(Node *root)
{
    vector<Node*> arr;
    Node* head = root;
    while(root) {
        arr.push_back(root);
        root = root->next;
    }
    int l = 0, r = arr.size() - 1;
    while(l<r) arr[l++]->next = arr[r--];   //Connect 0,1 to n-1,n-2
    l = 1, r = arr.size() - 1;      
    while(l<r) arr[r--]->next = arr[l++];   //connect n-1,n-2 to 1,2
    arr[arr.size()/2]->next = NULL;     //connect middle element to null
}

/*
Efficient Solution: O(1) Space and O(1) Time

1) Find the middle point using fast and slow method.
2) Split the linked list into two halves using found middle point in step 1.
3) Reverse the second half.
4) Do alternate merge of first and second halves.
*/
Node *reverse(Node *root) {   
    Node *prev = NULL;
    Node *curr = root;
    while(root!=NULL)
    {
        curr = root;
        root = root->next;
        curr->next = prev;
        prev = curr;
    }
    return prev;
}

Node *inplace(Node *root) {
    Node *fast = root;
    Node *slow = root;
    while(fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *head1 = root;
    Node *head2 = slow->next;
    head2 = reverse(head2);
    slow->next = NULL;
    
    Node *head = new Node(0);
    Node* curr = head;
    while (head1 || head2) {
        if (head1) {
            curr->next = head1;
            head1 = head1->next;
        }
        if (head2) {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }
    return head->next;
}

int main() {
    return 0;
}