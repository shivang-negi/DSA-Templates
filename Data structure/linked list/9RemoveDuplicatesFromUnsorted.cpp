#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node* next;
};
struct Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void removeDuplicates(struct Node* start)
{
	// Hash to store seen values,we could have also used two loops
	unordered_set<int> seen;

	struct Node* curr = start;
	struct Node* prev = NULL;
	while (curr != NULL) 
	{
		if (seen.find(curr->data) != seen.end()) 
		{	//Points to end of hash if element not present
			prev->next = curr->next;
			delete (curr);
		}
		else {
			seen.insert(curr->data);
			prev = curr;
		}
		curr = prev->next;
	}
}

void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

int main()
{
	struct Node* start = newNode(10);
	start->next = newNode(12);
	start->next->next = newNode(11);
	start->next->next->next = newNode(11);
	start->next->next->next->next = newNode(12);
	start->next->next->next->next->next = newNode(11);
	start->next->next->next->next->next->next = newNode(10);

	printf("Linked list before removing duplicates : \n");
	printList(start);

	removeDuplicates(start);

	printf("\nLinked list after removing duplicates : \n");
	printList(start);

	return 0;
}
