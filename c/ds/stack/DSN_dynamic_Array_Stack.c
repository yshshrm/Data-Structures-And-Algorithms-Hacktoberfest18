#include<stdio.h>
#include<stdlib.h>

struct DynArrStack{
    int top;
    int capacity;
    int *arr;
};

struct DynArrStack* createstack(){
    struct DynArrStack *S = (struct DynArrStack*)malloc(sizeof(struct DynArrStack));

    if(!S)
        return NULL;

    S->capacity=1;
    S->top=-1;
    S->arr=(int *)malloc(S->capacity*sizeof(int));
    if(!S){
        return NULL;
    }
    return S;
};

void doubleStack(struct DynArrStack* S){
    S->capacity*=2;
    S->arr=(int*)realloc(S->arr,S->capacity*sizeof(int));
}

int isEmpty(struct DynArrStack* S){
    return (S->top==-1);
};

int stacktop(struct DynArrStack* S){
    if(isEmpty(S)){
        printf("Stack Empty");
        return INT_MIN;
    }

    return (S->arr[S->top]);
};

void push(struct DynArrStack* S, int a){
    if((S->top)==S->capacity-1){
        printf("Stack Overflow\n");
        printf("------increasing_size\n");
        doubleStack(S);

        S->arr[++(S->top)]=a;
    }else{S->arr[++(S->top)]=a;}
};

int pop(struct DynArrStack* S){
    if(isEmpty(S)){
        printf("Stack Underflow");
        return -1;
    }else{return S->arr[(S->top)--];}
};

void deleteDynArrStack(struct DynArrStack* S){
    if(S){
        if(S->arr){
            free(S->arr);
        }
        free(S);
    }

    printf("STACK Destroyed");
}

int main(){
    struct DynArrStack* DA = createstack();
    push(DA,5);
    push(DA,3);
    push(DA,6);





}
