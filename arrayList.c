
#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int current_no_of_element=0;

void insert(int *a,int val,int pos){
    if(current_no_of_element==MAX){
        printf("List is full.\n");
        return;
    }
    else if(pos>=current_no_of_element){
        a[current_no_of_element]=val;
        current_no_of_element++;
    }
    else{
        for(int i=current_no_of_element-1;i>=pos;i--){
            a[i+1]=a[i];
        }
        a[pos]=val;
        current_no_of_element++;
    }
}


//Delete Function
void delete_by_pos(int *a, int pos){

    if(pos>=current_no_of_element || current_no_of_element==0){
        printf("No data Present at the given index\n");
        return;
    }
    else{
        for(int i=pos;i<current_no_of_element;i++){
            a[i]=a[i+1];
        }
        current_no_of_element--;
    }
}
//Delete by value 
void delete_by_val(int *a, int data){
    int i=0;
    for(;i<current_no_of_element;i++){
        if(a[i]==data) break;
    }
    if(i==current_no_of_element) printf("%d not in list\n",data);
    else{
         for(int j=i;j<current_no_of_element;j++){
            a[j]=a[j+1];
        }
        current_no_of_element--;
    }
}

//Display function
void display(int *a){
    printf("Data:\t");
    for(int i=0;i<current_no_of_element;i++){
        printf("%d\t",a[i]);
    }
}

int main(){
    int choice,data,pos;
    int a[MAX];
    
    while (choice!=5){
        printf("1. Insertion\n");
        printf("2. Deletion (By Position)\n");
        printf("3. Deletion (By Value)\n");
        printf("4. Display\n");
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
            insert(a,data,pos);
            printf("\n\n");
            break;
        case 2:
            printf("Enter Position: ");
            scanf("%d",&pos);
            delete_by_pos(a,pos);
            printf("\n\n");
            break;

        case 3:
            printf("Enter Value: ");
            scanf("%d",&data);
            delete_by_val(a,data);
            printf("\n\n");
            break;
        
        case 4:
            display(a);
            printf("\n\n");
            break;

        case 5:
            printf("Program terminated successfully...\n");
            exit(0);
        
        
        default:
            printf("Enter valid choice\n");
            printf("\n\n");
            break;
        }
    }

    return 0;
}