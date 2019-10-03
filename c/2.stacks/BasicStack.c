#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
    int top;
    unsigned capacity;
    int *array;
} ST;



ST* create() {
    int cap;
    printf("What is the stack capacity: ");
    scanf("%d", &cap);
    ST *s = (ST*)malloc(sizeof(ST));
    s->top = -1;
    s->capacity = cap;
    int *arr = (int*)malloc(sizeof(int) * cap);
    s->array = arr;
    return(s);
}
int isFull(ST *s) {
    if(s->top == s->capacity-1) return 1;
    else return 0;
}

int isEmp(ST *s) {
    if(s->top == -1) return 1;
    else return 0;
}

void push(ST *s) {
    int x, p;
    if(!isFull(s)) {
        printf("Enter a value: ");
        scanf("%d", &x);
        s->top++;
        p = s->top;
        s->array[p] = x;
        printf("%d added to the stack\n", x);
    }
    else printf("Stack full\n");
}

void pop(ST *s) {
    if(!isEmp(s)) {
        int x, p;
        p = s->top;
        x = s->array[p];
        s->top--;
        printf("%d popped outta the stack\n", x);
    }
    else printf("Empty stack\n");
}

int menu() {
    int c;
    printf("Enter choice: ");
    scanf("%d", &c);
    char ch;
    while( ( ch = getchar() ) != '\n' && ch != EOF );
    //Input buffer cleared
    return(c);
}

int main() {
    ST *s;
    s = create();
    printf("1. Push items\n2. Pop items\n3. Exit\n");
    while(1) {
        switch(menu()) {
            case 1: push(s); break;
            case 2: pop(s); break;
            case 3: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
