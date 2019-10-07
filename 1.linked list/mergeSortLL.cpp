//merge sort recursive
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;
node* midpoint_linkedlist(node *head)   // to get the mid node
{
    // Write your code here
    node* slow= head;
    node* fast= head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow= slow->next;
        fast= fast->next->next;
    }
    return slow;      // returning mid node
}
node* mergeTwoLLs(node *head1, node *head2) {    // to merge two sorted linked lists
    node* finalH = NULL;
    node* finalT = NULL;

    if(head1->data < head2->data)
      {
        finalH= head1;
        finalT= head1;
        head1= head1->next;
      }
    else
      {
        finalH= head2;
        finalT= head2;
        head2= head2->next;
      }
    while(head1!=NULL && head2!=NULL)
    {
       if(head1->data < head2->data)
       {
           finalT->next= head1;
           finalT= finalT->next;
           head1= head1->next;
       }
        else
        {
            finalT->next= head2;
            finalT= finalT->next;
            head2= head2->next;
        }
    }
    if(head2==NULL)
    {
        finalT->next= head1;
    }
    else if(head1==NULL)
    {
    finalT->next= head2;
    }


    return finalH;
}

node* mergeSort(node *head) {
    //write your code here
 if(head==NULL|| head->next==NULL)
 {
     return head ;
 }

node* mid= midpoint_linkedlist(head);
    node* midnext= mid->next;    // to get the node next to mid node
    mid->next=NULL;
    node* small=mergeSort(head);
    node* small1= mergeSort(midnext);
    node* finalhead= mergeTwoLLs(small, small1);

 return finalhead;
}

node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* head=takeinput();
    head= mergeSort(head);
    print(head);
    return 0;
}
