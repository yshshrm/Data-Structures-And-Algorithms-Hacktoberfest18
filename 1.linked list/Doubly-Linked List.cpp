#include<iostream>
#include<cstdlib>
using namespace std;
struct Node
{
    int INFO;
    struct Node * NEXT, * PREV;
};
void Create_Node(struct Node ** START,struct Node ** END,int n)
{
    int inf,i;
    struct Node * temp, * new_node;
    *START=*END=NULL;
    if(n<=0)
        cout<<"No elements to be inserted in the list!";
    *START=(struct Node *)malloc(sizeof(struct Node));
    if(*START==NULL)
    {
        cout<<"Memory can not be allocated!";
    }
    else
    {
        cout<<"Enter the data to be inserted in the element 1: ";
        cin>>inf;
        (*START)->INFO=inf;
        (*START)->PREV=NULL;
        (*START)->NEXT=NULL;
        temp=(*START);
        (*END)=temp;
        for(i=2;i<=n;i++)
        {
            new_node=(struct Node *)malloc(sizeof(struct Node));
            if(new_node==NULL)
            {
                cout<<"Memory can not be allocated!";
            }
            cout<<"Enter the data to be inserted in the element "<<i<<": ";
            cin>>inf;
            new_node->INFO=inf;
            new_node->PREV=temp;
            new_node->NEXT=NULL;
            temp->NEXT=new_node;
            (*END)=new_node;
            temp=new_node;
        }
    }
}
void Traverse(struct Node * START,struct Node * END)
{
    struct Node * temp=START;
    while(temp!=END)
    {
        cout<<temp->INFO<<" -> ";
        temp=temp->NEXT;
    }
    cout<<temp->INFO;
}
void Traverse_Reverse(struct Node * START,struct Node * END)
{
    struct Node * temp=END;
    while(temp!=START)
    {
        cout<<temp->INFO<<" -> ";
        temp=temp->PREV;
    }
    cout<<temp->INFO;
}
int main()
{
    struct Node * START, * END;
    int n;
    cout<<"Enter the number of nodes you want to create: ";
    cin>>n;
    Create_Node(&START,&END,n);
    Traverse(START,END);
    cout<<"\nThe linked list in reverse is: ";
    Traverse_Reverse(START,END);
    return 0;
}
