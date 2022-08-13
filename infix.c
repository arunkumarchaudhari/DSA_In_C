#include<stdio.h>
#include<stdlib.h>

#define MAX 100
typedef struct{
    int data[MAX];
    int top;
}STACK;


STACK s1; //declaring stack as globar variable


//PUSH Function:
int push(STACK *s1, char v){
    if(s1->top==MAX-1){
        printf("Overflow occured....\nTry again after deleting some data from the stack\n");
        return 1;
    }

    s1->top++;
    s1->data[s1->top]=v;
    return 0;
}

//POP Function:
int pop(STACK *s1,char * data){
    if(s1->top==-1){
        printf("Underflow condition occured...");
        return 1;
    }
    *data=s1->data[s1->top];
    s1->top--;
    return 0;
}
void init(STACK *s1){
    s1->top=-1;
}
//SOME OF USED FUNCTION INSIDE infixtopost Function:

//Defining getv function:
int getv(char a){
    int k=0;
    switch (a)
    {
    case '+':
    case '-':
        k=1;
        break;

    case '*':
    case '/':
        k=2;
        break;

    case '^':
        k=3;
        break;
    }

    return k;
}



int isEmpty(STACK s){
    if(s.top==-1) return 1;
    else return 0;
}

int isOperand(char c){
    if((c>='A' && c<='Z') || (c>='a' && c<='z') ) return 1;
    else return 0;
}

int isLH(char a, char b){
    if(getv(a) < getv(b)) return 1;
    else return 0;
}


//************************
//************************
//************************
//************************
//************************
//INFIX --->POSTFIX FUNCTION
void infixtopost(char *inf, char *outf){
    int i,j=0;
    int k;
    char t;

    while(inf[i]!='\0'){

        //if it is operand, directly send it to output..
        if(isOperand(inf[i])){
            outf[j]=inf[i];
            j++;
        }
        else if(inf[i]=='('){
            k=push(&s1,inf[i]);
        }
        else if(inf[i]==')'){
            while(1){
                k=pop(&s1,&t);
                if(t=='(') break;
                outf[j++]=t;
            }
        }

        //Now this else is for operator part....
        else{
            
            //first lets see stack is empty or not, if empty push any peratro comes..
            if(isEmpty(s1)){
               k=push(&s1,inf[i]);
            }
            else{

                //now need to pop, in order to perform any operation...
                k=pop(&s1,&t); //top element of stack is present in t

                //On the top element no chance of ")"
                if(t=='('){
                    k=push(&s1,t);
                    k=push(&s1,inf[i]);
                }
                else{

                    //Let's see LH condition first
                    if(isLH(t,inf[i])){
                        k=push(&s1,t);
                        k=push(&s1,inf[i]);
                    }
                    else{
                        outf[j]=t;
                        i--;
                    }
                }

            }
        }


        i++;
    }

    //Now lets pop out all the left out element from the stack:
    while((k=pop(&s1,&t))==0){
        outf[j]=t;
        j++;
    }
    outf[j]='\0';
}








//isHL Function:
int isHL(char a, char b){
    if(getv(a) > getv(b)) return 1;
    else return 0;
}



//REVESE FUNCTION FOR INFIX--->PREFIX
void reverse(char arr[]){
    
}



//************************
//************************
//************************
//************************
//************************
//INFIX --->PREFIX FUNCTION
void infixtoprefix(char *inf, char *outf){
    int i,j=0;
    int k;
    char t;

    //First lets reverse in input data,
    reverse(inf);

    while(inf[i]!='\0'){

        //if it is operand, directly send it to output..
        if(isOperand(inf[i])){
            outf[j]=inf[i];
            j++;
        }
        else if(inf[i]=='('){
            k=push(&s1,inf[i]);
        }
        else if(inf[i]==')'){
            while(1){
                k=pop(&s1,&t);
                if(t=='(') break;
                outf[j++]=t;
            }
        }

        //Now this else is for operator part....
        else{
            
            //first lets see stack is empty or not, if empty push any peratro comes..
            if(isEmpty(s1)){
               k=push(&s1,inf[i]);
            }
            else{

                //now need to pop, in order to perform any operation...
                k=pop(&s1,&t); //top element of stack is present in t

                //On the top element no chance of ")"
                if(t=='('){
                    k=push(&s1,t);
                    k=push(&s1,inf[i]);
                }
                else{

                    //Let's see HL condition first
                    if(isHL(t,inf[i])){
                        outf[j]=t;
                        i--;
                        
                    }
                    //for rest it will stay together,even for SS it will stay together
                    else{
                        k=push(&s1,t);
                        k=push(&s1,inf[i]);
                    }
                }

            }
        }


        i++;
    }

    //Now lets pop out all the left out element from the stack:
    while((k=pop(&s1,&t))==0){
        outf[j]=t;
        j++;
    }
    outf[j]='\0';

    //Reversing the data, in order to get result:
    reverse(outf);
}








//Display Function
void display(char *arr){
    int i=0;
    while(arr[i]!='\0'){
        printf("%c",arr[i]);
        i++;
    }
}

int main(){
    int i=0;
    init(&s1);
    int choice;
    char outf[100];
    char inf[]="A/B-C*E/K-P*Q/R";
    printf("Expression: A+B-(D*K+P)/R\n");
    printf("1.Infix ---->Postfix\n");
    printf("2.Infix ---->Prefix\n");
    printf("3.Exit\n");
    printf("Enter Your Choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        infixtopost(&inf , &outf);
        printf("Result: ");
        display(outf);
        printf("\n\n");
        break;
    
    case 2:
        printf("Coming soon..\n");
        break;
    
    case 3:
        printf("Program terminated successfully.....\n");
        exit(0);
        break;
    
    default:
        printf("Enter valid choice\n");
        break;
    }
    return 0;
}