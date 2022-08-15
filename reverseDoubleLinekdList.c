#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
    int data;
    struct node *next;
    struct node *prv;
} *head=NULL;

//Insertion of a node at any position.
void insert(struct node**h,int data,int pos){
    struct node *cur,*ptr;
    cur=malloc(sizeof(struct node));
    cur->data=data;
    cur->next=cur->prv=NULL;

    //No node 
    if(*h==NULL){
        *h=cur;
    }

    //At beginning of the node:
    else if(pos==0){
        cur->next=*h;
        (*h)->prv=cur;
        *h=cur;
    }
    else{
        ptr=*h;
        int i=0;
        while(i<pos-1 && ptr->next!=NULL){
            i++;
            ptr=ptr->next;
        }

        //At last
        if(ptr->next==NULL){
            cur->prv=ptr;
            ptr->next=cur;
        }
        else{
            cur->next=ptr->next;
            cur->prv=ptr;
            ptr->next->prv=cur;
            ptr->next=cur;
        }
    }
}


//Display:
void display(struct node *h){
    printf("Data:\t");
    while(h!=NULL){
        printf("%d  ",h->data);
        h=h->next;
    }
    printf("\n\n");
}

//Delete function.
void delete(struct node **h, int val){
    struct node *ptr;
    //No data
    if(*h==NULL){
        printf("List is empty\n");
    }
    else{
        ptr=*h;

        while(ptr!=NULL){
            if(ptr->data==val) break;
            ptr=ptr->next;
        }
        //Data not present
        if(ptr==NULL){
            printf("%d not present in the list\n",val);
        }
        else if(ptr==*h){
            (*h)->next->prv=NULL;
            *h=(*h)->next;
            free(ptr);
        }
        //Only one node:
        else if(ptr==*h && (*h)->next==NULL){
            *h=NULL;
            free(ptr);
        }
        //Last node deletion:
        else if (ptr->next==NULL){
            ptr->prv->next=NULL;
            free(ptr);
        }
        else{
            ptr->next->prv=ptr->prv;
            ptr->prv->next=ptr->next;
            free(ptr);
        }
    }
}


void reverse(struct node **h){
    struct node *ptr=*h,*ptr1;
    while(ptr1->next!=NULL){
        ptr1=ptr->next;
        ptr->next=ptr1->next;
        ptr1->next->prv=ptr;
        ptr1->next=*h;
        ptr1->prv=NULL;
        *h=ptr1;
    }
}

int main(){
    int choice;
    int data,pos;
    
    start:
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Display\n");
    printf("4. Reverse\n");
    printf("5. Exit\n");
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
        delete(&head,data);
        break;
    
    case 3:
        display(head);
        printf("\n\n");
        break;
    
    case 4:
        reverse(&head);
        printf("After Reversing ");
        display(head);
        printf("\n\n");
        break;

    case 5:
        printf("Program terminated successfully...\n");
        exit(0);
    
    
    default:
        printf("Enter valid choice\n");
        break;
    }

    goto start;
    return 0;
}