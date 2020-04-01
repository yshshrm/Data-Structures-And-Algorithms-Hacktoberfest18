//
//  main.cpp
//  Strings
//
//  Created by MacBook Pro on 7/31/18.
//  Copyright © 2018 MacBook Pro. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


//first implementation
//

class trieNode
{
public:
    char c;
    bool EOW;
    vector<trieNode>v;
    
    trieNode(char c,bool EOW)
    {
        this->c=c;
        this->EOW=EOW;
    }

};

class trie{
    
    vector<trieNode>v;
    
    public:
    
    void insert(string s)
    {
        insertNode(s, 0, v);
        
    }
    
    bool deleteString(string s)
    {
        return deleteNode(s, 0, v);
    }
    
    bool searchTree(string s)
    {
        return searchNode(s,0,v);
    }
    
    //counts the strings that start with the prefix s
    int countPrefix(string s)
    {
        return probeNode(s, 0, v);
    }
    
    
    //Utility functions
  private:
   void insertNode(string& s,int i,vector<trieNode> & v )
                {
                    
                    if(i==s.length()-1)
                    {
                        trieNode n(s[i],true);
                        v.push_back(n);
                        return;
                    }
                    bool found=false;
                    for(int j=0;j<v.size();j++)
                    {
                        if(v[j].c==s[i])
                        {
                            found=true;
                            insertNode(s, i+1, v[j].v);
                            break;
                            
                        }
                    }
                    
                    if(!found)
                    {
                        trieNode n(s[i],false);
                        v.push_back(n);
                        insertNode(s, i+1, v[v.size()-1].v);
                    }
//
                }
    
    
    bool deleteNode(string s,int i,vector<trieNode> & v)
    {
        int j=findinVec(s[i], v);
        if(j==-1) return false;
        
        if(i==s.length()-1)
        {
            
            
            if(v[j].v.size()==0&&v[j].EOW)
            {
                v.erase(v.begin()+j);
                return true;
            }
            else{
                if(v[j].EOW){ v[j].EOW=false; return true;}
                return false;
            }
            
            
        }
        bool checkNext = deleteNode(s, i+1, v[j].v);
        if(checkNext&&v[j].v.empty()) v.erase(v.begin()+j);
        return checkNext;
    }
    
    
    
    int findinVec(char c,vector<trieNode>& v)
    {
        for(int i=0;i<v.size();i++)
        {
            if(v[i].c == c) return i;
        }
        return -1;
    }
    
    bool searchNode(string &s,int i,vector<trieNode>&v)
    {
        int j = findinVec(s[i], v);
        if(i==s.length()-1)
        {
            
            if(j!=-1) return v[j].EOW;
        }
        
       
        if(j==-1) return false;
        else
        {
            return searchNode(s, i+1, v[j].v);
        }
    }
    
    int findPrefixes(vector<trieNode>& v)
    {
        int cnt=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].EOW) cnt++;
            cnt+=findPrefixes(v[i].v);
        }
        return cnt;
    }
    
   int probeNode(string & s,int i,vector<trieNode>&v)
    {
        int j=findinVec(s[i],v);
        if(j==-1) return 0;
        int cnt=0;
        if(i==s.length()-1)
        {
            if(v[j].EOW)cnt++;
            cnt+=findPrefixes(v[j].v);
        }
        else
        {
           return probeNode(s, i+1, v[j].v);
        }
        return cnt;
    }

   
    
};



void printDelete(bool b,string &s)
{
    if(b)printf("successfullyDeleted string %s\n",s.c_str());
    else
    {
        printf("string %s doesnot exist\n",s.c_str());
    }
}

void printCountPrefix(int cnt,string & s)
{
    printf("%d strings exist with prefix = %s\n",cnt,s.c_str());
}

int main(int argc, const char * argv[]) {
    // insert code here...

    
    trie t;
    t.insert("ab");
    t.insert("abc");
    t.insert("abcd");
    t.insert("bce");
    
    bool found=false;
    found=t.searchTree("ab");
    printf("ab found = %d\n",found);
    
    found=t.searchTree("bce");
    printf("bce found = %d\n",found);
    
    found=t.searchTree("abcd");
    printf("abcd found = %d\n",found);
    
    found=t.searchTree("a");
    printf("a found = %d\n",found);
    
    found=t.searchTree("bc");
    printf("bc found = %d\n",found);
    
    found=t.searchTree("lab");
    printf("lab found = %d\n",found);
    
    int count=t.countPrefix("ab");
    printCountPrefix(count,* new string("ab"));
    
    count=t.countPrefix("a");
    printCountPrefix(count,* new string("a"));
    
     count=t.countPrefix("bce");
    printCountPrefix(count,* new string("bce"));
    
    count=t.countPrefix("abc");
    printCountPrefix(count,* new string("abc"));
    
    found=t.deleteString("lab");
    printDelete(found,* new string("lab"));
    
    
    found=t.deleteString("ab");
    printDelete(found,* new string("ab"));
    
    
    count=t.countPrefix("ab");
    printCountPrefix(count,* new string("ab"));
    
    found=t.searchTree("ab");
    printf("ab found = %d\n",found);
    
    found=t.deleteString("bce");
    printDelete(found,* new string("bce"));
    
    found=t.searchTree("bce");
    printf("bce found = %d\n",found);
    
    found=t.deleteString("abc");
    printDelete(found,* new string("abc"));
    
    found=t.searchTree("abc");
    printf("abc found = %d\n",found);
    
    count=t.countPrefix("ab");
    printCountPrefix(count,* new string("ab"));
    
    found=t.deleteString("abcd");
    printDelete(found,* new string("abcd"));
    
    count=t.countPrefix("ab");
    printCountPrefix(count,* new string("ab"));
    
    found=t.searchTree("abcd");
    printf("abcd found = %d\n",found);
    
    
    return 0;
}
