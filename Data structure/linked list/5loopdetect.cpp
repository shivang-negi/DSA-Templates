#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

bool detectLoop(struct Node* h)
{
	unordered_set<Node*> s;
	while (h != NULL) {
		// If this node is already present
		// in hashmap it means there is a cycle
		// (Because you will be encountering the
		// node for the second time).
		if (s.find(h) != s.end()) //find function return to end of hash,when node not found.
			return true;

		// If we are seeing the node for
		// the first time, insert it in hash
		s.insert(h);

		h = h->next;
	}

	return false;
}

int main()
{
	struct Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);

	/* Create a loop for testing */
	head->next->next->next->next = head;

	if (detectLoop(head))
		cout << "Loop found";
	else
		cout << "No Loop";

	return 0;
}
