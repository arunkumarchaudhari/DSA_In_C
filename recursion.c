#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};



//Factorial of a number
int fact(int a){
    if(a==0) return 1;
    else return a*fact(a-1);
}


//Display LinkedList
void display(struct node *h){
    if(h!=NULL){
        printf("%d ",h->data);
        display(h->next);
    }
}

//Displaying LinkedList in reverse:
void rDisplay(struct node *h){
    if(h!=NULL){
        rDisplay(h->next);
        printf("%d ",h->data);
    }
}




int main(){


    return 0;
}