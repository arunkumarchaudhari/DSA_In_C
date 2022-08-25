//Implementation of Circular Queue in Circualr Linekd List
#include<stdio.h>
#include<stdlib.h>

//Creating ADT for circualr queue in Circular LinekdList
struct node{
    int data;
    struct node *next;
};
typedef struct {
    //If we will see the structure of CircularQueue in Circular LinkedList
    //We can see that in o(1) we can perofrm insertion and deletion if we know rear end of the queue.
    //So no need of defining fron end..we can manage with rear end itself
    struct node *rear; //Here r is Rearend
}CQueue;

//inint function to initialize rear
void init(CQueue *cq) {
    cq->rear=NULL;
}

//Insert function
int insert(CQueue *cq,int value) {
    struct node *cur;
    cur=malloc(sizeof(struct node));

    //if cur not created properly
    if(cur==NULL) return 1;

    cur->next=NULL;
    cur->data=value;

    //No node present means rear is null.
    if(cq->rear==NULL) {
        cq->rear=cur;
        cq->rear->next=cur;
    }
    //Some node already present
    else{
        cur->next=cq->rear->next; //assigning rear next i.e., front to cur next
        cq->rear->next=cur; 
        cq->rear=cur;
    }
    return 0;
}

//Delete Function
int delete(CQueue * cq,int *v) {

    //if no node present
    if(cq->rear==NULL){
        printf("Queue is empty\n");
        return 1;
    }

    struct node *ptr;
    ptr=cq->rear->next;
    //only one node is present
    if(cq->rear->next=cq->rear) {
        *v=ptr->data;
        cq->rear=NULL;
        free(ptr);
    }
    //If more than one node present
    else{
        *v=ptr->data;
        cq->rear->next=ptr->next;
        free(ptr);
    }
    return 0;
}

//Display Function
void display(CQueue *cq) {
    printf("CQueue\t:");
    if(cq->rear==NULL){
        printf("");
    }
    else{
        struct node *ptr;
        ptr=cq->rear->next;
        while(ptr!=cq->rear){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("%d ",ptr->data);
    }
    printf("\n\n");
    //NOTE: The reason behind using if else is that, when the list is empty,then also ptr is pointing to rear next which is null
    //      due to which is it terminating program.
}

int main(){
    
    CQueue q1;
    init(&q1);

    int value,choice,k;

    while(1) {
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
            scanf("%d",&value);
            k=insert(&q1,value);

            if(k==1) printf("Data Not inserted\n");
            else printf("%d inserted successfully...",value);
            printf("\n");

            break;
        case 2:
            k=delete(&q1,&value);
            if(k==0){
                printf("Data Deleted Successfully\n");
                printf("Deleted Data: %d",value);
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
    }


    return 0;
}