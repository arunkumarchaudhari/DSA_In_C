#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prv;
    struct node *next;
};

//Insertioin function:
void insert(struct node **h,int data,int pos){
    struct node *cur;
    struct node *ptr;
    cur=malloc(sizeof(struct node));
    cur->data=data;
    cur->next=cur->prv=NULL;

    //no data
    if(*h==NULL){
        *h=cur;
        (*h)->next=(*h)->prv=cur;
    }
    else if(pos==0){
        cur->prv=(*h)->prv;
        (*h)->prv->next=cur;
        cur->next=*h;
        (*h)->prv=cur;
        *h=cur;
    }
    else{
        ptr=*h;
        int i=0;
        while(i<pos-1){
            ptr=ptr->next;
            i++;
        }
        if(ptr->next==*h && (*h)->next!=*h){
            cur->next=*h;
            cur->prv=(*h)->prv;
            (*h)->prv->next=cur;
            (*h)->prv=cur;
        }
        else{
            cur->next=ptr->next;
            cur->prv=ptr;
            ptr->next->prv=cur;
            ptr->next=cur;  
        }
    }

}

//Display function
void display(struct node *h){
    printf("Data:\t");
    struct node *ptr;
    ptr=h;

    while(ptr->next!=h){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\t",ptr->data);
}

int main(){
    struct node *head=NULL;
    int choice;
    int data,pos;
    
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
        printf("Enter data: ");
        scanf("%d",&data);
        printf("Enter position: ");
        scanf("%d",&pos);
        insert(&head,data,pos);
        printf("\n%d inserted successfully...\n");
        break;
    case 2:
        printf("Enter data: ");
        scanf("%d",&data);
        // delete(&head,data);
        break;
    
    case 3:
        display(head);
        printf("\n\n");
        break;

    case 4:
        printf("Program terminated successfully...\n");
        exit(0);
    
    
    default:
        printf("Enter valid choice\n");
        break;
    }

    goto start;
    return 0;
}