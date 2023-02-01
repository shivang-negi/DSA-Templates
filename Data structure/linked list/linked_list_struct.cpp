#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

void insert_node(Node* root, int n, int x) {
	while(x-1) {
		if(!root) return;
		root = root->next;
		x--;
	}
	if(!root) return;
	Node* cur = new Node(n);
	Node* hold = root->next;
	root->next = cur;
	cur->next = hold;
}

int main() {
	Node* root = new Node(10);
	Node* second = new Node(20);
	Node* third = new Node(30);
	Node* fourth = new Node(40);

	root->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = NULL;

	insert_node(root,25,2);

	while(root) {
		cout<<root->data<<" ";
		root = root->next;
	}

    return 0;
}