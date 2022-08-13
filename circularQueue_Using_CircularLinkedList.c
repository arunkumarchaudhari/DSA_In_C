#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct{
    struct node *R;
}CQueue;

int insert(CQueue *q, int v){
    struct node *cur;
    cur=malloc(sizeof(struct node));
    
    if(cur==NULL) return 1;
    cur->data=v;

    if(q->R==NULL){
        cur->next=cur;
        q->R=cur;
    }
    else{
        cur->next=q->R->next;
        q->R->next=cur;
        q->R=cur;
    }
    return 0;
}

int delete(CQueue *q, int *v){

    if(q->R==NULL){
        printf("List is empty\n");
        return 1;
    }
    if(q->R->next==q->R){
        *v=q->R->data;
        free(q->R);
        q->R=NULL;
    }
    else{
        struct node *ptr=q->R->next;
        *v=ptr->data;
        q->R->next=ptr->next;
        free(ptr);
    }
    return 0;
}

void init(CQueue *q){
    q->R=NULL;
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