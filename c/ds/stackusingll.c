#include&lt;stdio.h&gt;
#include&lt;conio.h&gt;
#include&lt;malloc.h&gt;
struct node
{
int data;
struct node*next;
};
void insertathead(struct node** head,int d)
{
struct node* temp=(struct node*)malloc(sizeof(struct
node));
temp-&gt;data=d;
temp-&gt;next=*head;
*head=temp;
}
void pop(struct node** head)
{
struct node*temp=*head;
struct node*temp2=temp-&gt;next;
if(*head==NULL)
{
printf(&quot;\n Stack is empty&quot;);
}
else
{
free(temp);
*head=temp2;
}
}
int top(struct node* head)
{
if(head==NULL)
{
printf(&quot;\n Stack is empty&quot;);
return -1;
}
else

{
return head-&gt;data;
}
}
void main()
{
struct node* head=NULL;
insertathead(&amp;head,10);
insertathead(&amp;head,9);
insertathead(&amp;head,8);
insertathead(&amp;head,7);
pop(&amp;head);
int a=top(head);
printf(&quot;\n Top element is %d&quot;,a);
getch();
}
