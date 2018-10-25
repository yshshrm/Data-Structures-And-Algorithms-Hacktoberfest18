#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
    Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
    
protected:
    map<int,Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function
    
};

class LRUCache : public Cache{
public:
    LRUCache(int capacity)
    {
        cp = capacity;
    }
    
    int get(int key)
    {
        // iterate through map and print value for key, if found
        std::map<int,Node*>::iterator it;
        for (it = mp.begin(); it != mp.end(); ++it)
        {
            if (key == it->second->key)
            return it->second->value;
        }
        // else return -1
        return -1;
    }
    
    void set(int key, int value)
    {
        // create new node and set key and value
        Node* node = new Node(key, value);
        
        // check if cache is empty, if so set head/tail to current node
        if (mp.size() == 0)
        {
            tail = node;
            head = node;
            mp.insert(std::pair<int,Node*>(key, node));
            return;
        }
        
        // check if we already have this key - remove if so
        std::map<int,Node*>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
        {
            if (it->first == key)
            {
                /* If node to be deleted is head node */
                if(head->value == it->second->value)
                {
                    head = it->second->next;
                }
                /* Change next only if node to be deleted is NOT the last node */
                if(it->second->next != NULL)
                {
                    it->second->next->prev = it->second->prev;
                }
                /* Change prev only if node to be deleted is NOT the first node */
                if(it->second->prev != NULL)
                {
                    it->second->prev->next = it->second->next;
                }
                
                mp.erase(it);
            }
        }
        
        // add new node to map
        mp.insert(std::pair<int,Node*>(key, node));
        
        // add key to latest used position of cache (the start/head)
        node->next = head;
        head = node;
        
        // remove tail key,value pair if over capacity
        if (mp.size() > cp)
        {
            // set node to delete
            node = tail;
            
            tail = tail->prev;
            std::map<int,Node*>::iterator it;
            for (it = mp.begin(); it != mp.end(); it++)
            {
                if (it->second->value == node->value)
                {
                    mp.erase(it);
                }
            }
        }
    }
    
};
