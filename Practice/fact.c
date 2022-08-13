#include<stdio.h>
int main()
{
    int a;
    printf("Enter a number to get its factorial: ");
    scanf("%d",&a);
    int r=fact(a);
    printf("%d",r);
 return 0;
}

int fact(int a){
    if(a==0)
    return 1;
    else
    return a*(fact(a-1));
}