#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    // int data;
    char name[100];
    struct node *prv;
    struct node *next;
};

//Insertioin function:
void insert(struct node **h,char *n,int pos){
    struct node *cur;
    struct node *ptr;
    cur=malloc(sizeof(struct node));
    for(int i=0; n[i]!='\0'; i++){
        cur->name[i]=n[i];
    }
    int size=sizeof(cur->name);
    strncpy(n,cur->name,size);
    cur->name[size-1]='\0';
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
        cur->next=ptr->next;
        ptr->next->prv=cur;
        cur->prv=ptr;
        ptr->next=cur;
    }

}

//Display function
void display(struct node *h){
    printf("Data:\t");
    struct node *ptr;
    ptr=h;

    while(ptr->next!=h){
        printf("%s\t",ptr->name);
        ptr=ptr->next;
    }
    printf("%s\t",ptr->name);
}

int main(){
    struct node *head=NULL;
    int choice;
    int pos;
    char data[100];
    
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
        fflush(stdin);
        printf("Enter name: ");
        scanf("%[^\n]%*c",&data);
        printf("Enter position: ");
        scanf("%d",&pos);
        insert(&head,data,pos);
        printf("\n%s inserted successfully...\n",data);
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