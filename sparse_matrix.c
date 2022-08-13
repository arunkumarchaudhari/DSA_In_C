#include <stdio.h>
#include <stdlib.h>

struct node
{
    int r;
    int c;
    int v;
    struct node *next;
};

// Creation of sparse matrix:
void create(struct node **h)
{
    struct node *ptr, *cur;
    *h = malloc(sizeof(struct node));
    printf("Enter data for the matrix:\n");
    printf("T_rows T_cols T_non-zeroValue\n");
    scanf("%d%d%d", &(*h)->r, &(*h)->c, &(*h)->v);
    (*h)->next = NULL;
    ptr = *h;
    for (int i = 0; i < (*h)->v; i++)
    {
        cur = malloc(sizeof(struct node));
        Printf("Enter\n");
        printf("Row_no col_no value:  ");
        scanf("%d%d%d", &cur->r, &cur->c, &cur->v);
        cur->next = NULL;

        // No neeed for head==null, as we have already created head, so it won't be null at any condition
        ptr->next = cur;
        ptr = cur;
    }
}

//Add function
void add(struct node *h1,struct node *h2,struct node **h){
    
}

int main()
{

    struct node *h;
    create(&h);
    return 0;
}