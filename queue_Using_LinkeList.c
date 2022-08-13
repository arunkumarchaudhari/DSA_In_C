#include<stdio.h>
#include<stdlib.h>

struct  node
{
    int data;
    struct node *next;
};

typedef struct{
    struct node *front;
    struct node *rear;
}Queue;


//init function:
void init(Queue *q1){
    q1->front=NULL;
    q1->rear=NULL;
}


//INSERT FUNCTION:
int insert(Queue *q, int v){
    struct node *cur=malloc(sizeof(struct node));

    if(cur==NULL) return 1;

    cur->data=v;
    cur->next=NULL;

    if(q->front==NULL){
        q->front=q->rear=cur;
    }
    else{
        q->rear->next=cur;
        q->rear=cur;
    }
    return 0;

}

//DELETE FUNCTION:
int delete(Queue *q, int *v){

    struct node *ptr;
    if(q->front==NULL){
        printf("Queue is empty\n");
        return 1;
    }
    if(q->front==q->rear){
        ptr=q->front;
        *v=ptr->data;
        q->front=q->rear=NULL;
        free(ptr);
    }
    else{
        ptr=q->front;
        q->front=q->front->next;
        *v=ptr->data;
        free(ptr);
    }
    return 0;
}


//DISPLAY FUNCTION:
void display(Queue *q){
    printf("Queue: ");
    struct node *ptr;
    ptr=q->front;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    Queue q1;
    init(&q1);
    int data,choice,k;

    start:
    printf("\n\n");
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