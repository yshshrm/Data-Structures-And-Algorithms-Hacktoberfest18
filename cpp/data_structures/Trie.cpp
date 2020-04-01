#include <bits/stdc++.h>

using namespace std;

//A cleaner implementation for trie

const int alphabet_size=26;


struct TrieNode{
    struct TrieNode *children[alphabet_size];
    bool EndofWord; 
};

struct TrieNode *getNode(void){
    struct TrieNode *pNode = new TrieNode;
    pNode->EndofWord=false;
    for(int i=0;i<alphabet_size;i++){
        pNode -> children[i]=NULL;
    }
    return pNode;
}

void insert(struct TrieNode *root,string key){
    struct TrieNode *neww=root;

    for(int i=0;i<key.length();i++){
        int index = key[i] - 'a';
        if(!neww->children[index])
            neww->children[index] = getNode();
        neww=neww->children[index];
    }
    neww->EndofWord=true;
}

bool search(struct TrieNode *root,string key){
    struct TrieNode *neww=root;
    for(int i=0;i<key.length();i++){
        int index=key[i] - 'a';
        if(neww->children[index]==NULL)
            return false;
        neww=neww->children[index];
    }
    if(neww!=NULL && neww->EndofWord==true)
        return true;
    else
        return false;
}


int main(void){
    
    return 0;
}
