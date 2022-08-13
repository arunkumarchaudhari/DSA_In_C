#include<stdio.h>
#include<stdlib.h>

#define MAX 10
typedef struct{
    int data[MAX];
    int front;
    int rear;
}Queue;

//init function:
void init(Queue *q1){
    q1->front=-1;
    q1->rear=-1;
}

//INSERT FUNCTION:
int insert(Queue *q,int v){
    if(q->rear==MAX-1){
        printf("QF\n");
        return 1;
    }
    else if(q->rear==-1){
        q->front=q->rear=0;
        q->data[q->rear]=v;
    }
    else{
        q->rear++;
        q->data[q->rear]=v;
    }
    return 0;
}


//METHOD 1: DELETE FUNCTION:
//This is O(1), but memory utilization is very poor...
int delete(Queue *q, int *d){
    if(q->front==-1){
        printf("No data to delete\n");
        return 1;
    }
    else if(q->front==q->rear){
        *d=q->data[q->front];
        q->front=q->rear=-1;
        return 0;
    }
    else{
        *d=q->data[q->front];
        q->front++;
        return 0;
    }
    
}

//METHOD: 2 DELETE FUNCTION
//This is O(n) but memory is utilized fully...

int delete2(Queue *q, int *d){
    if(q->front==-1){
        printf("No data to delete\n");
        return 1;
    }
    else if(q->front==q->rear){
        *d=q->data[q->front];
        q->front=q->rear=-1;
        return 0;
    }
    else{
        *d=q->data[q->front];
        
        for(int i=q->front+1;i<=q->rear;i++){
            q->data[i-1]=q->data[i];
        }
        q->rear--;
        
        return 0;
    }
    
}

//DISPLAY FUNCTION:
void display(Queue *q){
    printf("Data in Queue: ");
    for(int i=q->front;i<=q->rear;i++){
        printf("%d ",q->data[i]);
    }
    printf("\n\n");
}

int main()
{
    Queue q1;
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
