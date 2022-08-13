#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *next;
    int data;
};

//insert function
void insert(struct node **h, int data, int pos){
    struct node *cur,*ptr;
    cur=malloc(sizeof(struct node));
    cur->data=data;
    cur->next=NULL;
    if(*h==NULL){
        *h=cur;
    }
    else if(pos==0){
        cur->next=*h;
        *h=cur;
    }
    else{
        ptr=*h;
        int i=0;
        while(i<pos-1 && ptr->next!=NULL){
            i++;
            ptr=ptr->next;
        }
        cur->next=ptr->next;
        ptr->next=cur;
    }

}

//display functon
void disp(struct node *h){
    printf("List: ");
    while(h!=NULL){
        printf("%d ",h->data);
        h=h->next;
    }
}

//swap function as per given input k
void swap(struct node *h, int k){
    struct node *ptr1,*ptr=NULL,*ptr2;
    int i=0;
    while(1){

        //positioning ptr and ptr1 at the respective place
        if(ptr==NULL){
            ptr=h;
        }
        else{
            ptr=ptr1->next;
        }
        ptr1=ptr;
        while(i<k-1 && ptr1->next!=NULL){
            ptr1=ptr1->next;
            i++;
        }

        // display part
        while(ptr!=ptr1){
            for(ptr2=ptr; ptr2->next!=ptr1;ptr2=ptr2->next){
                printf("%d ",ptr1->data);
                ptr1=ptr2;
            }
        }
        printf("%d",ptr->data);
        if(ptr1->next==NULL) break;

    }
}

int main(){

    struct node *head=NULL;
    int n,k;
    printf("Enter number of nodes to be created: ");
    scanf("%d",&n);
    printf("Node is filled with random data\n");
    for(int i=0;i<n;i++){
        insert(&head,rand()%100,0);
    }
    printf("Before swap\n");
    disp(head);
    printf("\nEnter value of k in order to swap: ");
    scanf("%d",&k);
    printf("\nAfter swap\n");
    swap(head,k);
    disp(head);
    return 0;
}