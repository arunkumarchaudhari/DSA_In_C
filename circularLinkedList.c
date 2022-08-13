#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node *next;
    int data;
};

//insertion function....
void insert(struct node **h,int data,int pos){
    struct node *cur,*ptr;
    cur=malloc(sizeof(struct node));
    cur->data=data;
    cur->next=NULL;

    //if nothing is present in list:
    if(*h==NULL){
        *h=cur;
        (*h)->next=cur;
    }

    //if inserted at beginning:
    else if(pos==0){
        ptr=*h;
        while(ptr->next!=*h){
            ptr=ptr->next;
        }
        cur->next=*h;
        ptr->next=cur;
        *h=cur;
    }

    //rest position...
    else{
        ptr=*h;
        int i=0;
        while(i<pos-1){
            i++;
            ptr=ptr->next;
        }
        cur->next=ptr->next;
        ptr->next=cur;
    }
}

//Display function:
void display(struct node *h){
    struct node *ptr;
    ptr=h;
    if(h!=NULL){
        do{
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }while(ptr!=h);
    }
}

void delete(struct node **h,int val){
    int checker=0;
    struct node *ptr,*prev;
    if(*h==NULL){
        printf("List is empty, Please insert data to perform this operation..\n");
    }
    else{
        ptr=*h;
        while(ptr->data!=val && ptr->next!=*h){
            prev=ptr;
            ptr=ptr->next;

        }
        if(ptr->next==*h && ptr->data!=val){
            printf("Data not present in List\n");
        }
        //only one node..and deleting that...
        else if((*h)=(*h)->next){
            *h=NULL;
            free(ptr);
            checker=1;
        }
        //first node deletion...
        else if(ptr==*h){
            struct node *temp=*h;
            while(temp->next!=*h){
                temp=temp->next;
            }
            *h=ptr->next; //or *h->next;
            temp->next=*h;
            free(ptr);
            checker=1;
        }
        //rest...
        else{
            prev->next=ptr->next;
            free(ptr);
            checker=1;
        }
    }
    if(checker==1) printf("\n%d Deleted successfully from list\n\n",val);
}
int main(){
	int c,c1,d,p;
	printf("This Program is for Circular LinkedList\n");
	struct node *head=NULL;
	start:
    printf("\n\n");
	printf("\n1.Insertion\n");
	printf("2.Display\n");
	printf("3.Delete\n");
	printf("4.Exit\n");
	printf("Enter your choice : ");
	scanf("%d",&c);
	int data,pos;
	
	switch(c){
		case 1:
			printf("Enter data and position to be inserted: ");
			scanf("%d%d",&data,&pos);
			insert(&head,data,pos);
			break;
		case 2:
			printf("\nCircular LinkedList: ");
			display(head);
			break;
		case 3:
			printf("Enter data to be deleted from LinkedList: ");
			scanf("%d",&d);
			delete(&head,d);
			break;
		case 4:
			printf("Program terminated successfully.....\n");
			exit(0);
		default:
			printf("Enter valid choice as mention above\n");
	}
	goto start;
	
	return 0;
}