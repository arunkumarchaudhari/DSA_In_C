#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct{
    struct node *top;
}STACK;

void init(STACK *s){
    s->top=NULL;
}

//PUSH Function
int push(STACK *s,int v){
    struct node *cur;
    cur=malloc(sizeof(struct node));
    if(cur==NULL){
        printf("Overflow condition....\n");
        return 1;
    }
    else{
        cur->data=v;
        cur->next=s->top;
        s->top=cur;
        return 0;

    }
}

//POP Function
int pop(STACK *s, int *v){
    
    if(s->top==NULL){
        printf("Underflow condition....\n");
        return 1;
    }
    else{
        struct node *ptr;
        ptr=s->top;
        *v=ptr->data;
        s->top=s->top->next;
        free(ptr);
        return 0;
    }
}

//Display Function
void display(STACK s){
    printf("Data: ");
    while(s.top!=NULL){
        printf("%d ",s.top->data);
        s.top=s.top->next;
    }
    printf("\n\n");
}


int main(){
    int data,temp,choice;

    STACK s1;
    init(&s1);

    start:
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Enter Choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("Enter data to be pushed: ");
        scanf("%d",&data);
        temp=push(&s1,data);
        if(temp==0) printf("%d pushed successfully inside stack.\n",data);

        printf("\n\n");
        break;

    case 2:
        temp=pop(&s1,&data);
        if(temp==0){
            printf("Successfully poped\n");
            printf("Data poped : %d\n",data);
        }
        else{
            printf("\nPlease try again after inserting some data into stack\n");
        }
        printf("\n\n");
        break;

    case 3:
        display(s1);
        break;

    case 4:
        printf("Program terminated successfully....\n");
        exit(0);

    default:
        printf("Please enter a valid choice\n");
        printf("\n");
    }

    goto start;

    return 0;
}