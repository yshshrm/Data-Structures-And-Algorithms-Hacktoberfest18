#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *next;
};
void create();
void reverse();
void release();
void display();
struct node* head;
int main()
{
    head = NULL;

    printf("Enter Values: ");
    create();
    //Reverse...
    reverse();
    printf("The Reversed list is:\n");
    display();
    release();

    return 0;
}

void reverse()
{int c,k=0;

    struct node* j=head;
    while(j->next!=NULL)
    {if(k%2==0)
        {c=j->num;
    j->num=(j->next)->num;
    (j->next)->num=c;}
    k++;j=j->next;}

}

void create()
{
    int c, ch;
    struct node *temp, *rear;

    do
    {

        scanf("%d", &c);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = c;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
        printf("Press (1) to continue or (0) to stop: ");
        scanf("%d", &ch);
    } while (ch != 0);
    printf("\n");
}

void display()
{struct node* t=head;
    while (t != NULL)
    {
        printf("%d\t", t->num);
        t = t->next;
    }
    printf("\n");
}

void release()
{
    struct node *temp = head;
    head = head->next;
    while ((head) != NULL)
    {
        free(temp);
        temp = head;
        (head) = (head)->next;
    }
}
