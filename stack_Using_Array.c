#include<stdio.h>
#include<stdlib.h>

// int max;
#define MAX 10
typedef struct{
    int data[MAX];
    int top;
}STACK;


//PUSH Function:
int push(STACK *s, int v){
    if(s->top==MAX-1){
        printf("Overflow occured....\nTry again after deleting some data from the stack\n");
        return 1;
    }

    s->top++;
    s->data[s->top]=v;
    return 0;
}

//POP Function:
int pop(STACK *s,int * data){
    if(s->top==-1){
        printf("Underflow condition occured...");
        return 1;
    }
    *data=s->data[s->top];
    s->top--;
    return 0;
}

//Display Function:
void display(STACK *s){
    printf("Data in STACK: ");
    for(int i=0;i<=s->top;i++){
        printf("%d ",s->data[i]);
    }

    printf("\n\n");
}

void init(STACK *s){
    s->top=-1;
}

int main(){
    // printf("Enter total size of stack: ");
    // scanf("%d",&max);
    printf("This is 10 size stack.\n");
    STACK s1;
    init(&s1);
    int temp,data=0,choice;

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
        display(&s1);
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