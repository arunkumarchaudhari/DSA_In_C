#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    int r1,c1,r2,c2;
    int sum;
    printf("Enter row and column for 1st matrix: ");
    scanf("%d%d",&r1,&c1);
    printf("Enter row and column for 2nd matrix: ");
    scanf("%d%d",&r2,&c2);
    
    int a[r1][c1];
    int b[r2][c2];
    int r[r1][c2];
    if(c1!=r2){
        printf("Multiplication not possible");
        return 0;
    }
    
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            a[i][j]=(int)rand()%10;
        }
    }
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            b[i][j]=(int)rand()%10;
        }
    }

    //Multiplication
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            sum=0;
            for(int k=0;k<c1;k++){
                sum+=a[i][k]*b[k][j];
            }
            r[i][j]=sum;
        }
    }

    printf("Matrix 1\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2\n");
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    printf("Resultant Matrix\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            printf("%d ",r[i][j]);
        }
        printf("\n");
    }
    


    return 0;
}