#include<stdio.h>
#include<stdlib.h>
struct node{
        int info;
        struct node *next;
        };

typedef struct node NODE;

NODE* addStart(NODE* head, int n){
                NODE *p= (NODE*)malloc(sizeof(NODE));
                p->info= n;
                p->next= head;
                return p;
            }

NODE* addEnd(NODE* head, int n){
        if (head==NULL){
                head=(NODE*)malloc(sizeof(NODE));
                head->info=n;
                head->next=NULL;
                return head;
                }
           NODE *p, *q;
           p=head;
           while(p->next!=NULL){
                p=p->next;
                }
           q=(NODE*)malloc(sizeof(NODE));
           q->info=n;
           q->next=NULL;
           p->next=q;
           return head;
           }

NODE* addXB(NODE* head, int n, int x){
        NODE *q, *p= head;
        while(p->info!=x){
                  q=p;
                  p=p->next;
                  }
       NODE *r= (NODE*) malloc(sizeof(NODE));
       q->next=r;
       r->next=p;
       r->info=n;
       return head;
       }

NODE* addXA(NODE* head, int n, int x){
        NODE *p, *q=head;
        while(q->info!=x){
                q=q->next;
               }
       p=(NODE*) malloc(sizeof(NODE));
       p->next=q->next;
       p->info=n;
       q->next=p;
       return head;
       }

NODE* delStart(NODE* head){
        if(head==NULL){
                printf("List is empty\n");
                return NULL;
                }
        NODE *p= head;
        head=head->next;
        free(p);
        return head;
        }

NODE* delEnd(NODE* head){
        if(head==NULL){
                printf("List is empty\n");
                return NULL;
        }
        NODE *p= head, *q;
        while(p->next!=NULL){
                q=p;
                p=p->next;
                }
       q->next=NULL;
       free(p);
       return head;
       }

NODE* delX(NODE *head, int x){
        NODE *p= head, *q=head;
        while(p->info!=x){
                p=q;
                p=p->next;
                }
         q->next=p->next;
         free(p);
         return head;
         }

NODE* disp(NODE *head){
        NODE *p= head;

        while(p!=NULL){
                printf("%d \t", p->info);
                p=p->next;
        }
        printf("\n\n");
}

void main(){
        int x,n;
        NODE* head=NULL;
        while(1){
               int choice;
               printf("1) Start of the link list\n");
               printf("2) End of the link list\n");
               printf("3) Position before information x\n");
               printf("4) Position after information x\n");
               printf("5) Delete at start of link list\n");
               printf("6) Delete at the end of the link list\n");
               printf("7) Delete given element\n");
               printf("8) Display link list\n");
               printf("9) Quit\n");
               printf("Your choice:\t ");
               scanf("%d", &choice);
               switch(choice){
                        case 1:
                                printf("Enter element to add to list: ");
                                scanf("%d", &n);
                                head=addStart(head, n);
                                break;
                        case 2:
                                printf("Enter element to add to end of list: ");
                                scanf("%d", &n);
                                head=addEnd(head, n);
                                break;
                       case 3:
                                printf("Enter element to add to list: ");
                                scanf("%d", &n);
                                printf("\nEnter element which this should go before: ");
                                scanf("%d", &x);
                                addXB(head, n,x);
                                break;
                       case 4:
                                printf("Enter element to add to list: ");
                                scanf("%d", &n);
                                printf("Enter element which this should go after: ");
                                scanf("%d", &x);
                                head=addXA(head, n,x);
                                break;
                        case 5:
                                printf("deleted from start list\n", head=delStart(head));
                                break;
                        case 6:
                                printf("deleted from end of list \n", head=delEnd(head));
                                break;
                        case 7:
                                printf("Enter x:");
                                scanf("%d", &x);
                                printf("deleted from list\n", delX(head,x));
                                break;
                        case 8:
                                disp(head);
                                break;
                       case 9:
                               exit(1);
                       default :
                               printf("Number enter not correct\n");
                              }
                            }
}
