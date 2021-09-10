#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    int size;
    char *arr;
};

int isFull(struct stack *s)
{
    if(s->top == s->size-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct stack *s)
{
    if(s->top == -1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack *s , char val)
{
    if(isFull(s))
    {
        printf("Stack Overflow");
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}
char pop(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow");
    }
    else
    {   char val = s->arr[s->top];
        s->top--;
        return val;
    }
}
int isMatched(char a ,char b)
{
    if(a == '(' && b == ')')
    {
        return 1;
    }

    if(a == '{' && b == '}')
    {
        return 1;
    }
    if(a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}
int isparanthesis(char *exp)
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 100;
    s->arr = (char*)malloc(s->size*(sizeof(char)));
    int popped;

    for(int i =0 ; exp[i]!='\0' ; i++){

        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(s , exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){

             if(isEmpty(s))
            {
                return 0;   
            }
            popped = pop(s);

            if(!isMatched(popped , exp[i]))
            {
                return 0;
            }     

        }
    }
    if(isEmpty(s))
    {
        return 1;
    }
    return 0;
}


int main()
{
    char *exp = "8[{(*)9(*)}7";
    if(isparanthesis(exp))
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
}
