#include<stdio.h>
#include<stdlib.h>

void f1(int *a,int size){
    printf("Displaying array: ");
    for(int i=0;i<size;i++){
        printf("%d ",a[i]);
    }
}

int main()
{
    int *a=malloc(20*sizeof(int));
    for(int i=0;i<20;i++){
        a[i]=rand()%100;
    }
    f1(a,20);

 return 0;
}