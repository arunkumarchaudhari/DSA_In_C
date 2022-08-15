#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
    int data;
    struct node *next;
} *head=NULL;

//Insertion of a node at any position.
void insert(struct node**h,int data,int pos){
    struct node *cur;
    cur=malloc(sizeof(struct node));
    cur->data=data;
    cur->next=NULL;
    if(*h==NULL){
        *h=cur;
    }
    else{
        if(pos==0){
            cur->next=*h;
            *h=cur;
        }
        else{
            struct node *ptr;
            ptr=*h;
            int i=0;
            while(i<pos-1 && ptr->next!=NULL){
                ptr=ptr->next;
                i++;
            }
            cur->next=ptr->next;
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
    if(*h==NULL){
        printf("No data to delete\n");
    }

    else{
    //Positioning ptr at the correct place
        struct node *ptr,*prev;
        ptr=prev=*h;
        while(ptr!=NULL){
            if(ptr->data==val){
                break;
            }
            else{
                prev=ptr;
                ptr=ptr->next;
            }
        }
        if(ptr==NULL){
            printf("%d not found\n",val);
        }
        else if(ptr==*h){
            *h=(*h)->next;
            free(ptr);
        }
        else{
            prev->next=ptr->next;
            free(ptr);
        }

    }
    
}
//Reverse the node of the linked list
void reverse(struct node **h){
    struct node *ptr=*h,*ptr1;
    while(ptr->next!=NULL){
        ptr1=ptr->next;
        ptr->next=ptr1->next;
        ptr1->next=*h;
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