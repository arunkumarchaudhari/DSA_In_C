#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prv;
}*head=NULL;

void insert(struct node **h,int data,int pos){
	struct node *cur,*ptr;
	cur=malloc(sizeof(struct node));
	cur->data=data;
	cur->next=cur->prv=NULL;
	
	//if no data present....
	if(*h==NULL){
		*h=cur;
	}
	
	//if inserted at starting of double linked list...
	else if(pos==0){
		cur->next=*h;
		(*h)->prv=cur;
		*h=cur;
	}
	
	//now to insert at end or somewhere in the middle we have to take ptr to that position..
	//So lets fixed ptr to the desired position...
	
	else{
		ptr=*h;
		int i=0;
		while(ptr->next!=NULL && i<pos-1){
			ptr=ptr->next;
			i++;
		}
		
		//if ptr->next==NULL means to insert at end...
		if(ptr->next==NULL){
			cur->prv=ptr;
			ptr->next=cur;
		}
		else {
			cur->prv=ptr;
			cur->next=ptr->next;
			ptr->next->prv=cur;
			ptr->next=cur;	
		}
		
	}
	
}

//Display function.....
void display(struct node *h){
	while(h!=NULL){
		printf("%d ",h->data);
		h=h->next;
	}
	printf("\n\n");
}

//delete by value...
void delete(struct node **h,int v){
	struct node *ptr;
	if(*h==NULL){
		printf("List is empty..Nothing to delete\n");
	}
	else{
		ptr=*h;
		int checker =0;
		//positioning ptr to the location....
		while(ptr!=NULL){
			if(ptr->data==v){
				break;
			}
			else{
				ptr=ptr->next;
			}
		}
		//data not found..
		if(ptr==NULL){
			printf("Data not found...\n");
			checker=1;
		}
		//oney one node present..nd to delete that node.
		else if(*h==ptr && ptr->next==NULL){
			*h=NULL;
			free(ptr);

		}
		//last node deletion...
		else if(ptr->next==NULL){
			ptr->prv->next=NULL;
			free(ptr);
		}
		//first node deletion..
		else if(ptr==*h && ptr->next!=NULL){
			*h=(*h)->next;
			(*h)->prv=NULL;
			free(ptr);
		}
		//any node in bewteen..
		else{
			ptr->prv->next=ptr->next;
			ptr->next->prv=ptr->prv;
			free(ptr);
		}

		if(!checker) printf("\n\nDeleted Successfully....\n\n");
	}
}

int main(){
	int c,c1,d,p;
	printf("This Program is for Double LinkedList\n");
	struct node *head=NULL;
	start:
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
			printf("\nDouble LinkedList: ");
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