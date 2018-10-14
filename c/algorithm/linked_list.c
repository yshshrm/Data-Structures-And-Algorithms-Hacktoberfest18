#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *Insert(struct node *, int);
void Print_List(struct node *);
void Remove_List(struct node *);

int main(int argc, char **argv)
{
    struct node *head;

    head = NULL;

    head = Insert(head, 10);
    head = Insert(head, 20);

    Print_List(head);

    Remove_List(head);

    head = NULL;

    return 0;
}

struct node *Create_New_Node(int);
struct node *Head_Insert(struct node *, int);
struct node *Queue_Insert(struct node *, int);
struct node *Insert(struct node *, int);
void Print_List(struct node *);
void Remove_List(struct node *);

struct node *Insert(struct node *top, int elem)
{
    if(top == NULL)
    {
        top = Head_Insert(top, elem);
    }
    else
    {
        top = Queue_Insert(top, elem);
    }

    return top;
}

struct node *Create_New_Node(int elem)
{
    struct node *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));

    if(new_node != NULL)
    {
        new_node -> info = elem;
        new_node -> next = NULL;
    }

    return new_node;
}


struct node *Head_Insert(struct node *top, int elem)
{
    struct node *new_node = Create_New_Node(elem);

    if(new_node != NULL)
    {
        new_node -> next = top;
    }

    return new_node;
}

struct node *Queue_Insert(struct node *top, int elem)
{
    if(top != NULL)
    {
        if(top -> next != NULL)
        {
            top -> next = Queue_Insert(top -> next, elem);
        }
        else
        {
            struct node *new_node = Create_New_Node(elem);

            if(new_node != NULL)
            {
                 top -> next = new_node;
            }
        }
    }

    return top;
}

void Print_List(struct node *top)
{
    while(top != NULL)
    {
        printf("\nInfo : %d\tAddress : %u\tNext link address : %u\n", top -> info, top, top -> next);
        top = top -> next;
    }

    return;
}

void Remove_List(struct node *top)
{
    if(top != NULL)
    {
        Remove_List(top -> next);
        top -> next = NULL;
        free(top);
    }

    return;
}
