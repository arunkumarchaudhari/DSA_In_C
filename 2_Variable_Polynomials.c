#include<stdio.h>
#include<stdlib.h>
struct node {
    int coef;
    int expx;
    int expy;
    struct node *next;
};

void create(struct node **h) {
    struct node *cur,*ptr;
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cur=malloc(sizeof(struct node));
        printf("Enter coef: ");
        scanf("%d",&cur->coef);
        printf("Enter exp X: ");
        scanf("%d",&cur->expx);
        printf("Enter exp Y: ");
        scanf("%d",&cur->expy);
        cur->next=NULL;
        if(*h==NULL){
            *h=cur;
            ptr=cur;
        }
        else {
            ptr->next=cur;
            ptr=cur;
        }

    }
    
}

//Display Function
void display(struct node *h){
    while(h->next!=NULL){
        printf("%dX%dY%d ",h->coef,h->expx,h->expy);
        h=h->next;
        if(h->expx!=0 || h->expy!=0){
            printf("+");
        }
        if(h->expx==0 && h->expy!=0) printf("+");
        if(h->expx!=0 && h->expy==0) printf("+");

        printf("\t");
    }
    printf("%dX%dY%d ",h->coef,h->expx,h->expy);
    printf("\n\n");
}


int main(){

    struct node *h1;
    h1=NULL;
    create(&h1);
    printf("Displaying Polynomials:\n");
    display(h1);

    return 0;
}