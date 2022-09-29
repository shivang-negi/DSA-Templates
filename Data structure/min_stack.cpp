#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data,min;
    Node* prev;
    Node(int x, int m,Node* p) {
        data = x;
        min = m;
        prev = p;
    }
};

class minStack {
public:
    Node *head = NULL;

    void push(int x) {
        if(head==NULL) head = new Node(x,x,NULL);
        else head = new Node(x,min(x,head->min),head);
    }

    void pop() {
        Node* temp = head;
        head = head->prev;
        delete temp;
    }

    int top() {
        return head->data;
    }

    int getMin() {
        return head->min;
    }
};

int main() {
    minStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.pop();
    st.pop();
    cout<<st.top()<<" ";
    cout<<st.getMin();
    return 0;
}