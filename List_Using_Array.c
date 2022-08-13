#include<stdio.h>
#include<stdlib.h>
int max,current_no_of_element=0;


//INSERT FUNCTION
void insert(int *a,int value,int position){
    //case 1 if list is full
    if(current_no_of_element==max){
        printf("List is full\nPlease delete some data in order to insert new data\n");
        return;
    }
    //if inserted at any blank position where data is not present 
    else if(position>=current_no_of_element){
        a[current_no_of_element]=value;
        current_no_of_element++;
        printf("Data inserted successfully...");
    }

    //now inserted at the position where data is already present
    else{
        //first we need to move the data in order to insert...
        for(int i=current_no_of_element-1;i>=position;i--){
            a[i+1]=a[i];
        }
        //now we can insert at out position.
        a[position]=value;
        current_no_of_element++;

        printf("Data inserted successfully...");
    }
    
}

//DELETE BY POSITION
void delete_by_position(int *a,int pos){
    if(current_no_of_element==0 || (pos>=current_no_of_element)){
        printf("No data present at given position to delete.");
        return;
    }
    else{
        for(int i=pos+1;i<=current_no_of_element-1;i++){
            a[i-1]=a[i];
        }
        current_no_of_element--;
        printf("Data delete successfully...");
    }
}

void delete_by_value(int *a,int val){
    int i=0;
    //first search element in list
    for(;i<current_no_of_element;i++){
        if(val==a[i])
        break;
    }

    //if data not present in list means value of i has become current_no_of_element
    if(i==current_no_of_element){
        printf("Data not present in the list\nPlease provide valid data\nThank you!");
    }
    else{
        for(int j=i+1;j<=current_no_of_element-1;j++){
            a[j-1]=a[j];
        }
        current_no_of_element--;
        printf("%d deleted successfully from the list....",val);
    }
}

//DISPLAY FUNCTION
void display(int *a){
    printf("Data in the List: ");
    for(int i=0;i<current_no_of_element;i++){
        printf("%d\t",a[i]);
    }
}
int main(){
    printf("Enter max size of List: ");
    scanf("%d",&max);
    int a[max],d,pos,val,choice,choice2;
    start:
    printf("\n\n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("Enter data and position: ");
        scanf("%d%d",&d,&pos);
        insert(a,d,pos);
        break;
    case 2:
        start2:
        printf("\n\n");
        printf("1.Delete by Value\n");
        printf("2.Delete by position\n");
        printf("3.Go back to previous menu\n");
        printf("4.Terminate program from here\n");
        printf("Choice: ");
        scanf("%d",&choice2);

        switch (choice2)
        {
        case 1:
            
            printf("Enter data to be delete from the list: ");
            scanf("%d",&val);
            delete_by_value(a,val);
            break;
        case 2:
            printf("Enter position from where you want to delete data: ");
            scanf("%d",&pos);
            delete_by_position(a,pos);
            break;
        case 3:
            goto start;
            break;
        case 4:
            printf("Program terminated successfully....");
            exit(0);
            break;
        
        default:
            printf("Enter valid choice\n");
            goto start2;
            break;
        }

        break;
    case 3:
        display(a);
        break;
    case 4:
        printf("Program terminated successfully...");
        exit(0);
        break;
    
    default:
        printf("Enter valid choice\nThank You!");
    }

    goto start;
    return 0;
}