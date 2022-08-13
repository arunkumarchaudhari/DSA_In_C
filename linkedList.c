#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
};

//Insertion.....
void insert(struct node **head,int data,int position){
	struct node *cur,*ptr;
	cur=malloc(sizeof(struct node));
	cur->next=NULL;
	cur->data=data;
	
	//Now its time to see all posible case of insertion....
	//case 1: if nothing is present i.e., head=null
	if(*head==NULL){
		*head=cur;
	}
	//case 2: if inserted at staring....
	else if(position==0){
		cur->next=*head;
		*head=cur;
	}
	//case 3 and 4 : if inserted in between or at the end....
	else{
		ptr=*head;
		
		//moving ptr to the position where insertion will take place..
		int i=0;
		while(i<position-1 && ptr->next!=NULL){
			i++;
			ptr=ptr->next;
		}
		//insertion
		cur->next=ptr->next;
		ptr->next=cur;
	}
	
}

//display......
void display(struct node *head){
	while(head!=NULL){ // we cant write head->next as it will ignore last value...
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n\n");
}

//Display Using Recursion:
void recdisplay(struct node *h){
    if(h!=NULL){
        printf("%d ",h->data);
        display(h->next);
    }
	printf("\n\n");
}

//Display Reverse using Recursion:
void revRecursionDisp(struct node *h){
	if(h!=NULL){
		revRecursionDisp(h->next);
		printf("%d ",h->data);
	}
	printf("\n\n");
}

//delete......by value
void deleteByVal(struct node **h,int value){
	struct node *ptr,*prv;
	int checker =0;
	//if list is empty i.e., head is null
	if(*h==NULL){
		printf("List is empty.\n");
	}
	else{
		//before deleting lets fix the position of ptr and prv
		//as per our design prv most stand one step behind the ptr...
		ptr=*h;
		while(ptr!=NULL){
			if(ptr->data==value){
				break;
			}else{
				prv=ptr;
				ptr=ptr->next;
			}
		}
		//fixing position of ptr and prv done...now let delete the node
		
		//if value doesnot present in the linkedlist
		if(ptr==NULL){
			printf("%d is not present in the list\n",value);
			checker =1;
			
		}
		//if only one node or deleting first node...
		else if(ptr==*h){
			*h=ptr->next;
			free(ptr);
		}
		
		//deleting rest of the node....
		else{
			prv->next=ptr->next;
			free(ptr);
		}
		
		if(!checker){
			printf("\nDeleted successfully.....\n\n");	
		}
		
	}
}

//delete....by position
void deleteByPos(){

}
int main(){
	int c,c1,d,p;
	printf("This Program is for LinkedList\n");
	struct node *head=NULL;
	start:
	printf("\n1.Insertion\n");
	printf("2.Display\n");
	printf("3.Display in Reverse\n");
	printf("4.Delete\n");
	printf("5.Exit\n");
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
			printf("LinkedList: ");
			display(head);
			break;

		case 3:
			printf("Reverse LinkedList: ");
			revRecursionDisp(head);
			break;
			
		case 4:
			printf("\n1.By Value\n");
			printf("2.By Position\n");
			printf("Enter your choice: ");
			scanf("%d",&c1);
			switch(c1){
				case 1:
					printf("Enter data to be deleted from LinkedList: ");
					scanf("%d",&d);
					deleteByVal(&head,d);
					break;
				case 2:
					printf("Enter position from where you want to delete data: ");
					scanf("%d",&p);
					printf("Work is under progress.....\n\n");
					
					break;
				default:
					printf("Enter valid choice....\n");
			}
			
			break;
		case 5:
			printf("Program terminated successfully.....\n");
			exit(0);
		default:
			printf("Enter valid choice as mention above\n");
	}
	goto start;
	
	return 0;
}
