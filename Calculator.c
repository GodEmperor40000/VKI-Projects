#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

typedef struct stack
{
    int data[MAX];
    int top;
}stack;

typedef struct stak2
{
    char data[MAX];
    int top;
}stack2;

int calculation (char postfix[], int finres);
int precedence(char);
void init(stack *);
int empty(stack *);
int full(stack *);
int pop(stack *);
void push(stack *,int);
int top(stack *);   //value of the top element
void infix_to_postfix(char infix[],char postfix[]);

void main()
{
    stack s;
    stack2 v;
    char x,token, vsp1, vsp2, vsp3, vsp4;
    int  i,j, res, finres, Num, Num2;
    init(&s);
    init(&v);
    j=0;
    i=0;


    char infix[30],postfix[30];
    //int finres = 0;
    printf("Enter an infix expression(eg: 5+2*4): ");
    gets(infix);
    infix_to_postfix(infix,postfix);
    printf("\nPostfix expression: %s",postfix);

    for(int r=0; postfix[r] != '\0'; r++){

        token = postfix[r];

        if(isalnum(token) != 0){
            Num = atoi(&token);
            push(&v, Num);


        }
        else if(token == ' '){
            i = pop(&v);

            itoa(i, &vsp1, 10);
            j = top(&v);

            itoa(j, &vsp2, 10);
            strncat(&vsp2, &vsp1, 10);

            push(&v, &vsp3);
        }
        else{
            i = pop(&v);

            j = pop(&v);

            switch(token){
                case '+' :
                    res = j + i;

                    break;
                case '-' :
                    res = j - i;

                    break;
                case '*' :
                    res = j * i;

                    break;
                case '/' :
                    res = j / i;

                    break;
                case '^' :
                    res = j ^ i;

                    break;
            }
            push(&v, res);
        }

    }
    finres = pop(&v);
    printf("\n Final result: %d", res);
}

void infix_to_postfix(char infix[],char postfix[])
{
    stack s;
    char x,token;
    int i,j;    //i-index of infix,j-index of postfix
    init(&s);
    j=0;

    for(i=0;infix[i]!='\0';i++)
    {
        token=infix[i];
        if(isalnum(token))
            postfix[j++]=token;
        else
            if(token=='(')
               push(&s,'(');
        else
            if(token==')')
                while((x=pop(&s))!='(')
                      postfix[j++]=x;
                else
                {
                    while(precedence(token)<=precedence(top(&s))&&!empty(&s))
                    {
                        x=pop(&s);
                        postfix[j++]=x;
                    }
                    push(&s,token);
                }
    }

    while(!empty(&s))
    {
        x=pop(&s);
        postfix[j++]=x;
    }

    postfix[j]='\0';
}

int precedence(char x)
{
    if(x=='(')
        return(0);
    if(x=='+'||x=='-')
        return(1);
    if(x=='*'||x=='/'||x=='%')
        return(2);

    return(3);
}

void init(stack *s)
{
    s->top=-1;
}

int empty(stack *s)
{
    if(s->top==-1)
        return(1);

    return(0);
}

int full(stack *s)
{
    if(s->top==MAX-1)
        return(1);

    return(0);
}

void push(stack *s,int x)
{
    s->top=s->top+1;
    s->data[s->top]=x;
}

int pop(stack *s)
{
    int x;
    x=s->data[s->top];
    s->top=s->top-1;
    return(x);
}

int top(stack *p)
{
    return (p->data[p->top]);
}

int calculation(char postfix[], int finres){

    stack s;
    char x,token;
    int i,j, res;
    init(&s);
    j=0;

    for(int i=0; postfix[i] != '\0'; i++){

        token = postfix[i];
        if(isalnum(token) != 0)
            push(&s, token);
        else{
            i = pop(&s);
            j = pop(&s);
            if(token == '+') res = i + j;
            if(token == '-') res = i - j;
            if(token == '*') res = i * j;
            if(token == '/') res = i / j;
            if(token == '^') res = i ^ j;
            push(&s, res);
        }

    }
    finres = pop(&s);
    return finres;
}
