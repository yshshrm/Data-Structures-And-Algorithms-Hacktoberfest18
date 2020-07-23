#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* node = new Node;

    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void inverse( struct Node* node){
    if(node == NULL){
        return;
    } else{
        struct Node* temp;

        inverse(node->left);
        inverse(node->right);

        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

void print(struct Node* node){
    if(node == NULL){
        return;
    }

    print(node->left);
    cout<<node->data<<" ";
    print(node->right);
}

main(){
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<"Before traversal ";
    print(root);

    inverse(root);

    cout<<"\nAfter traversal ";
    print(root);

    return 0;
}
