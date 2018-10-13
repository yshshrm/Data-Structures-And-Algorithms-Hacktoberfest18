#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct cell{
    int content;
    struct cell * next;

};
typedef struct cell cell;
cell *cell_create(int content){
    cell*a=(cell*)malloc(sizeof(cell));
    if(a==NULL){
        printf("heap alaninda yer ayrilamadi");

    }
    a->content=content;
    a->next=NULL;
    return a;

}
void list_end_add(int content,cell**list_head){
    cell*a=cell_create(content);
    if(*list_head==NULL){
        a->next=*list_head;
        *list_head=a;
    }
    else{
        cell*x=*list_head;
        while(x->next!=NULL){
            x=x->next;

        }
        x->next=a;
    }
}
void list_write(cell*list_head){
    if(list_head!=NULL){
        printf("%4d",list_head->content);
        list_write(list_head->next);

    }
    else
        printf("\n");
}
int sequantial(cell*list){
    if(list==NULL) return 1;
    if(list->next==NULL) return 1;
    int prev=list->content;
    cell*temp=list->next;
    while(temp!=NULL){
        if(prev>temp->content){
            return printf("No");
        }
        prev=temp->content;
        temp=temp->next;
    }
    return printf("Yes");




}
int min(cell*list){
    int es=list->content;
    list=list->next;
    cell*iter;
    if(list->next==NULL){
                es=list->content;
            }
    while(list!=NULL){

           if(list->content<es)
                es=list->content;

            list=list->next;


    }
    return es;
}
void list_separate(cell**list,cell*evenlist){
    //cell*c=(cell*)malloc(s<izeof(cell));
    cell*b;
    cell*temp;

    cell*temp2=*list;
    while(temp2!=NULL){

        if((temp2->content)%2!=0){
            temp2=temp2->next;
        }
        else{
            if(evenlist==NULL){
                    evenlist=(cell*)malloc(sizeof(cell));
                    evenlist->content=temp2->content;
                    evenlist->next=NULL;
                    temp2=temp2->next;

            }
             else{
                    while(evenlist->next!=NULL){
                        evenlist=evenlist->next;
                    }
                    evenlist->next=temp2;
                    temp2=temp2->next;
                }


        }



    }
    list_write(evenlist);

}
void erase (int index,cell**list){
    int i=1;
    cell*a;
    cell*b=*list;
    if(i==index){
        a=*list;
        *list=(*list)->next;
        free(a);



    }
    else{
        while(i!=index-1){
            b=b->next;
            i++;
        }
        a=b->next;
        b->next=a->next;
        free(a);
    }
    return *list;

}
int main()
{
    cell*list=NULL;
    cell*evenlist=NULL;
    //list_end_add(0,&list1);
    list_end_add(1,&list);
    list_end_add(2,&list);
    list_end_add(3,&list);
    list_end_add(6,&list);
    //list_write(list);
    list_separate(&list,evenlist);
    //erase(1,&list);
    list_write(list);
    sequantial(list);

    //list_write(evenlist);
    //printf("\n%d",min(list));
    return 0;
}

