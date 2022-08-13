#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct{
    int data[MAX];
    int f;
    int r;
}CQueue;

void init(CQueue *q){
    q->f=-1;
    q->r=-1;
}

int insert(CQueue *q, int v){
    if(q->f==(q->r+1)%MAX){
        printf("FULL\n");
        return 1;
    }
    if(q->r==-1){
        q->f=q->r=0;
        q->data[q->r]=v;
    }
    else{
        q->r=(q->r+1)%MAX;
        q->data[q->r];
    }
    return 0;
}

int delete(CQueue *q, int *v){

    if(q->f==-1){
        printf("List is empty\n");
        return 1;
    }
    if(q->f=q->r){
        *v=q->data[q->f];
        q->f=q->r=-1;
    }
    else{
        *v=q->data[q->f];
        q->f=(q->f+1)%MAX;
    }
    return 0;
}

//DISPLAY FUNCTION:
void display(CQueue *q){
    printf("Data: ");

    if(q->f==q->r){
        printf("%d",q->data[q->f]);
    }
    else if(q->f<q->r){
        for(int i=q->f;i<=q->r;i++){
            printf("%d ",q->data[i]);
        }
    }
    else{
        for(int i=q->f;i<MAX;i++){
            printf("%d ",q->data[i]);
        }
        for(int i=0;i<=q->r;i++){
            printf("%d ",q->data[i]);
        }
    }
    printf("\n\n");
}

int main(){
    
    CQueue q1;
    init(&q1);

    int data,choice,k;

    start:
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("Enter data to be inserted: ");
        scanf("%d",&data);
        k=insert(&q1,data);

        if(k==1) printf("Data Not inserted\n");
        else printf("%d inserted successfully...",data);
        printf("\n");

        break;
    case 2:
        k=delete(&q1,&data);
        if(k==0){
            printf("Data Deleted Successfully\n");
            printf("Deleted Data: %d",data);
        }
        else{
            printf("\nTry again\n");
        }
        printf("\n");
        break;
    case 3:
        display(&q1);
        break;

    case 4:
        printf("Program terminated successfully...\n");
        exit(0);
        break; //no need of break...automatically whole program will terminate.
    
    default:
        printf("Enter valid choice\n");
        break;
    }

    goto start;


    return 0;
}