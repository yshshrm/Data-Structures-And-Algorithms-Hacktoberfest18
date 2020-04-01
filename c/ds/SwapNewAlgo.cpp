#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Node{
    public:
        Node* left;
        Node* right;
        int v;    
};

void printInorder(Node* node){
    if(node == NULL)
        return;
    
    if(node->left != NULL)
        printInorder(node->left);
    
    cout << node->v << " ";
    
    if(node->right != NULL)
        printInorder(node->right);
    
    
}

void swapTree(Node* node, int K, int h){
    if(node == NULL)
        return;
    
    if(h % K == 0){
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
    swapTree(node->left, K, h+1);
    swapTree(node->right, K, h+1);
}

int main() {
    int N;
    cin >> N;
    map<int, Node*> table;
    Node* root = new Node();
    root->v = 1;
    root->left = NULL;
    root->right = NULL;
    table[1] = root;
    for(int i=1; i<=N; i++){
        int left, right;
        cin >> left >> right;
        if(left != -1){
            Node* l = new Node();
            l->v = left;
            l->left = NULL;
            l->right = NULL;
            table[i]->left = l;
            table[left] = l;
        }
        else{
            table[i]->left = NULL;
        }
        if(right != -1){
            Node* r = new Node();
            r->v = right;
            r->left = NULL;
            r->right = NULL;
            table[i]->right = r;
            table[right] = r;
        }
        else{
            table[i]->right = NULL;
        }
        
    }
    
    //printInorder(node);
    //cout << endl;

    int T;
    cin >> T;
    while(T--){
        int K;
        cin >> K;
        swapTree(root, K, 1);
        printInorder(root);
        cout << endl;
    }

    return 0;
}
