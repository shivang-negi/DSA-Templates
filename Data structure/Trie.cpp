#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
	TrieNode *children[26];
	bool isEndOfWord;
};

TrieNode* getNewNode(void) {
	TrieNode *pNode = new TrieNode;
	pNode->isEndOfWord = false;

	for (int i = 0; i < 26; i++) pNode->children[i] = NULL;

	return pNode;
}

void insert(struct TrieNode *root, string key) {
	TrieNode *node = root;

	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!node->children[index])
		node->children[index] = getNewNode();

		node = node->children[index];
	}
	node->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key)
{
	struct TrieNode *node = root;

	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!node->children[index])
		return false;

		node = node->children[index];
	}

	return (node->isEndOfWord);
}

int main()
{
	string keys[] = {"the", "a", "there","answer", "any", "by","bye", "their" };
	int n = sizeof(keys)/sizeof(keys[0]);

	TrieNode *root = getNewNode();
	for (int i = 0; i < n; i++) insert(root, keys[i]);

	search(root, "the")? cout << "Yes\n" :cout << "No\n";
	search(root, "these")? cout << "Yes\n" :cout << "No\n";
	search(root, "their")? cout << "Yes\n" :cout << "No\n";
	search(root, "thaw")? cout << "Yes\n" :cout << "No\n";
	return 0;
}