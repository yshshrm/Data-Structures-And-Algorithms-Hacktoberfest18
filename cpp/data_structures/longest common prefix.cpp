//Runtime 4ms , memory usage 10.1mb
#include<bits/stdc++.h> 
using namespace std; 
#define ALPHABET_SIZE (26) 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 

struct TrieNode 
{ 
	struct TrieNode *children[ALPHABET_SIZE]; 
	bool isLeaf; 
}; 

struct TrieNode *getNode(void) 
{ 
	struct TrieNode *pNode = new TrieNode; 

		pNode->isLeaf = false; 

		for (int i = 0; i < ALPHABET_SIZE; i++) 
			pNode->children[i] = NULL; 


	return pNode; 
} 

void insert(struct TrieNode *root, string key) 
{ 
	int length = key.length(); 
	int index; 

	struct TrieNode *pCrawl = root; 

	for (int level = 0; level < length; level++) 
	{ 
		index = CHAR_TO_INDEX(key[level]); 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

	pCrawl->isLeaf = true; 
} 

int countChildren(struct TrieNode *node, int *index ) 
{ 
	int count = 0; 
	for (int i=0; i<ALPHABET_SIZE; i++) 
	{ 
		if (node->children[i] != NULL) 
		{ 
			count++; 
			*index = i; 
		} 
	} 
	return (count); 
} 

string walkTrie(struct TrieNode *root) 
{ 
	struct TrieNode *pCrawl = root; 
	int index; 
	string prefix; 

	while (countChildren(pCrawl, &index ) == 1 && 
			pCrawl->isLeaf == false) 
	{ 
		pCrawl = pCrawl->children[index]; 
		prefix.push_back('a'+index); 
	} 
	return (prefix); 
} 

class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
    
        int n=arr.size();
        struct TrieNode *root = getNode(); 
    
    	for (int i = 0; i < n; i++) 
	     	insert(root, arr[i]); 
  
	     return walkTrie(root); 
        
        
    }
};
