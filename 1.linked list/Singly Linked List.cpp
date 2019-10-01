#include<iostream>

using namespace std;

struct node{
    int info;
    node *next;
}*start,*newptr,*save,*ptr;

node* createnode(int);
void insert(node*);
void display(node*);

int main(){
    start=NULL;
    int info;char ch='y';

    while(ch=='y'){
        cout<<"Enter Info for new Node\n";
        cin>>info;
        cout<<"Creating new Node...\n";
        newptr=createnode(info);

        if(newptr!=NULL){
            cout<<"New Node created\n";
        }
        else{
            cout<<"Node can't be created\n";
        }

        insert(newptr);
        cout<<"\nList is:\n";
        display(start);
        cout<<"\npress y to Insert more\n";
        cin>>ch;
    }

    return 0;
}

node *createnode(int n){
    ptr=new node;
    ptr->info=n;
    ptr->next=NULL;
    return ptr;
}

void insert(node* np){
    if(start ==NULL){
        start=np;
    }
    else{
        save=start;
        start=np;
        np->next=save;
    }
}

void display(node * np){
    while(np!=NULL){
        cout<<np->info<<"->";
        np=np->next;
    }
}
