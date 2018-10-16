#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

void insertNode(Node **head, int data)
{
    Node *n = malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    struct Node *ptr = *head;
    if (*head == NULL)
    {
        *head = n;
        return;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = n;
}

Node *mergeLinkedLists(head1, head2)
{
    Node *head = NULL;
    Node *p1 = head1, *p2 = head2;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            insertNode(&head, p1->data);
            p1 = p1->next;
        }
        else
        {
            insertNode(&head, p2->data);
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        insertNode(&head, p1->data);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        insertNode(&head, p2->data);
        p2 = p2->next;
    }
    return head;
}

void printList(Node *head)
{
    Node *ptr = head;
    printf("Elements entered are: \n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    int n = 0, num = 0;
    Node *head1 = NULL, *head2 = NULL;
    while (1)
    {
        printf("Enter element to be inserted: ");
        scanf("%d", &n);
        if (n == -1)
        {
            break;
        }
        insertNode(&head1, n);
    }
    printList(head1);
    while (1)
    {
        printf("Enter element to be inserted: ");
        scanf("%d", &n);
        if (n == -1)
        {
            break;
        }
        insertNode(&head2, n);
    }
    printList(head2);
    Node *head = mergeLinkedLists(head1, head2);
    printList(head);
    return 0;
}