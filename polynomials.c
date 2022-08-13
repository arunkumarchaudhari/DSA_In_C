#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coe, exp;
    struct node *next;
};

// creation of polynomials using linkedlist...
void create(struct node **h)
{
    struct node *cur, *ptr;
    int no_of_terms;
    printf("Enter number of terms in the polynomials: ");
    scanf("%d", &no_of_terms);

    for (int i = 0; i < no_of_terms; i++)
    {
        cur = malloc(sizeof(struct node));
        printf("Enter cof and exp: ");
        scanf("%d%d", &cur->coe, &cur->exp);
        cur->next = NULL;

        if (*h == NULL)
        {
            *h = cur;
            ptr = cur;
        }
        else
        {
            ptr->next = cur;
            ptr = cur;
        }
    }
}

// Join function
void join(struct node **h1, struct node *h2)
{
    if (*h1 == NULL)
        *h1 = h2;
    else
    {
        struct node *ptr;
        for (ptr = *h1; ptr->next != NULL; ptr = ptr->next)
            ;
        ptr->next = h2;
    }
}

// SIMPLIFY FUNCTION**
// This will just add two polymonials
void simplify(struct node **h)
{
    struct node *ptr, *ptr1, *prev;
    ptr = *h;
    while (ptr != NULL)
    {
        prev = ptr;
        for (ptr1 = ptr->next; ptr1 != NULL; ptr1 = ptr1->next)
        {
            if (ptr1->exp == ptr->exp)
            {
                ptr->coe = ptr->coe + ptr1->coe;
                prev->next = ptr1->next;
                free(ptr1);
                ptr1 = prev;
            }
            prev = ptr1; // before ptr1 jumps, lets bring prev there then ptr1 to be jumped, in order to keep prev behind.
        }
        ptr = ptr->next;
    }
}

// Multiplication function:
void multiply(struct node *h1, struct node *h2, struct node **h)
{
    struct node *ptr1, *ptr2, *cur, *ptr;
    for (ptr1 = h1; ptr1 != NULL; ptr1 = ptr1->next)
    {
        for (ptr2 = h2; ptr2 != NULL; ptr2 = ptr2->next)
        {

            // lets create new to store value
            cur = malloc(sizeof(struct node));
            cur->coe = ptr1->coe * ptr2->coe;
            cur->exp = ptr1->exp + ptr2->exp;
            cur->next = NULL;

            if (*h == NULL)
            {
                *h = cur;
                ptr = *h;
            }
            else
            {
                ptr->next = cur;
                ptr = cur;
            }
        }
    }
}

// Display function:
// this function is defined in order to track polynomials thats it..
void display(struct node *h)
{
    while (h != NULL)
    {
        if (h->exp == 0)
        {
            printf("%d ", h->coe);
        }
        else
        {
            printf("%dX^%d + ", h->coe, h->exp);
        }
        h = h->next;
    }
    printf("\n");
}

// This is modify function, here I am going to make negative of 2nd polynomials in order to perform substraction.
void modify(struct node **h)
{
    struct node *ptr;
    ptr = *h;
    while (ptr != NULL)
    {
        ptr->coe *= -1;
        ptr = ptr->next;
    }
}

int main()
{
    struct node *h1, *h2, *h;
    h1 = h2 = NULL;
    int choice;
    printf("First Polynomials:\n");
    create(&h1);
    printf("Second Polynomials:\n");
    create(&h2);
    printf("Entered Polynomials are:\n");
    display(h1);
    display(h2);
    printf("\n1.Additioin\n");
    printf("2.Subracation\n");
    printf("3.Multiplication\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        join(&h1, h2);
        simplify(&h1);
        printf("Result: ");
        display(h1);
        break;
    case 2:
        modify(&h2); // this will change sign of h2 opposite.(means + to - and - to +)
        join(&h1, h2);
        simplify(&h1);
        printf("Result: ");
        display(h1);
        break;

    case 3:
        multiply(h1, h2, &h);
        simplify(&h);
        display(h);
        break;

    default:
        printf("Enter a valid choice\n");
    }

    printf("\nProgram terminated successfully...\n");

    return 0;
}